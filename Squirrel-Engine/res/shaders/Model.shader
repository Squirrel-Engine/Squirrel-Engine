#shader vertex
#version 430 core
//VertexShader
//////////////
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in vec3 tangent;
layout(location = 4) in vec3 bitangent;

out mat3 TBN;
out vec2 TexCoords;
out vec3 FragPos;
out vec3 FragPosTangentSpace;
out vec3 ViewPosTangentSpace;;

uniform mat4 viewProjection;
uniform mat4 model;
uniform vec3 viewPos;
void main()
{
    // Use the normal matrix to maintain the orthogonal property of a vector when it is scaled non-uniformly
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * tangent);
    vec3 B = normalize(normalMatrix * bitangent);
    vec3 N = normalize(normalMatrix * normal);
    TBN = mat3(T, B, N);

    TexCoords = texCoords;
    FragPos = vec3(model * vec4(position, 1.0f));
 
    gl_Position = viewProjection * vec4(FragPos, 1.0);
}

#shader fragment
#version 430 core
//FragmentShader
////////////////
out vec4 color;
in mat3 TBN;
in vec2 TexCoords;
in vec3 FragPos;
in vec3 FragPosTangentSpace;
in vec3 ViewPosTangentSpace;

#define MAX_DIR_LIGHTS 5
#define MAX_POINT_LIGHTS 5
#define MAX_SPOT_LIGHTS 5
const float PI = 3.14159265359;
uniform vec3 viewPos;

struct Material {
    sampler2D albedo;
    sampler2D normal;
    sampler2D metallic;
    sampler2D roughness;
    sampler2D ao;
    sampler2D displacement;
};
struct PointLight {
    vec3 position;

    float intensity;
    vec3 lightColour;
    float attenuationRadius;
};
uniform Material material;
uniform PointLight pointLight;

vec3 CalculatePointLightRadiance(vec3 albedo, vec3 normal, float metallic, float roughness, vec3 fragToView, vec3 baseReflectivity);
// Cook-Torrance BRDF functions adopted by Epic for UE4
float NormalDistributionGGX(vec3 normal, vec3 halfway, float roughness);
float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness);
float GeometrySchlickGGX(float cosTheta, float roughness);
vec3 FresnelSchlick(float cosTheta, vec3 baseReflectivity);

void main()
{
   // material properties
    vec3 albedo = texture(material.albedo, TexCoords).rgb;
    float albedoAlpha = texture(material.albedo, TexCoords).w;
    vec3 normal = texture(material.normal, TexCoords).rgb;
    float metallic = texture(material.metallic, TexCoords).r;
    float roughness = texture(material.roughness, TexCoords).r;
    float ao = texture(material.ao, TexCoords).r;

    normal = normalize(TBN * normalize(normal * 2.0 - 1.0));

    vec3 fragToView = normalize(viewPos - FragPos);
    vec3 reflectionVec = reflect(-fragToView, normal);

    // Dielectrics have an average base specular reflectivity around 0.04, and metals absorb all of their diffuse (refraction) lighting so their albedo is used instead for their specular lighting (reflection)
    vec3 baseReflectivity = vec3(0.04);
    baseReflectivity = mix(baseReflectivity, albedo, metallic);

    // Calculate per light radiance for all of the direct lighting
    vec3 directLightIrradiance = vec3(0.0);
    directLightIrradiance += CalculatePointLightRadiance(albedo, normal, metallic, roughness, fragToView, baseReflectivity);
  
    // Calcualte ambient IBL for both diffuse and specular
    vec3 ambient = vec3(0.05) * albedo * ao;
  
    color = vec4(ambient + directLightIrradiance, albedoAlpha);
}

vec3 CalculatePointLightRadiance(vec3 albedo, vec3 normal, float metallic, float roughness, vec3 fragToView, vec3 baseReflectivity) {
    vec3 pointLightIrradiance = vec3(0.0);

    for (int i = 0; i < 1; ++i) {
        vec3 fragToLight = normalize(pointLight.position - FragPos);
        vec3 halfway = normalize(fragToView + fragToLight);
        float fragToLightDistance = length(pointLight.position - FragPos);

        // Attenuation calculation (based on Epic's UE4 falloff model)
        float d = fragToLightDistance / pointLight.attenuationRadius;
        float d2 = d * d;
        float d4 = d2 * d2;
        float falloffNumerator = clamp(1.0 - d4, 0.0, 1.0);
        float attenuation = (falloffNumerator * falloffNumerator) / ((fragToLightDistance * fragToLightDistance) + 1.0);
        vec3 radiance = pointLight.intensity * pointLight.lightColour * attenuation;

        // Cook-Torrance Specular BRDF calculations
        float normalDistribution = NormalDistributionGGX(normal, halfway, roughness);
        vec3 fresnel = FresnelSchlick(max(dot(halfway, fragToView), 0.0), baseReflectivity);
        float geometry = GeometrySmith(normal, fragToView, fragToLight, roughness);

        // Calculate reflected and refracted light respectively, and since metals absorb all refracted light, we nullify the diffuse lighting based on the metallic parameter
        vec3 specularRatio = fresnel;
        vec3 diffuseRatio = vec3(1.0) - specularRatio;
        diffuseRatio *= 1.0 - metallic;

        // Finally calculate the specular part of the Cook-Torrance BRDF (max 0.1 stops any visual artifacts)
        vec3 numerator = specularRatio * normalDistribution * geometry;
        float denominator = 4 * max(dot(fragToView, normal), 0.1) * max(dot(fragToLight, normal), 0.0) + 0.001; // Prevents any division by zero
        vec3 specular = numerator / denominator;

        // Also calculate the diffuse, a lambertian calculation will be added onto the final radiance calculation
        vec3 diffuse = diffuseRatio * albedo / PI;

        // Add the light's radiance to the irradiance sum
        pointLightIrradiance += (diffuse + specular) * radiance * max(dot(normal, fragToLight), 0.0);
    }

    return pointLightIrradiance;
}
// ----------------------------------------------------------------------------
float NormalDistributionGGX(vec3 normal, vec3 halfway, float roughness) {
    float a = roughness * roughness;
    float a2 = a * a;
    float normDotHalf = dot(normal, halfway);
    float normDotHalf2 = normDotHalf * normDotHalf;

    float numerator = a2;
    float denominator = normDotHalf2 * (a2 - 1.0) + 1.0;
    denominator = PI * denominator * denominator;

    return numerator / denominator;
}

float GeometrySmith(vec3 normal, vec3 viewDir, vec3 lightDir, float roughness) {
    return GeometrySchlickGGX(max(dot(normal, viewDir), 0.0), roughness) * GeometrySchlickGGX(max(dot(normal, lightDir), 0.0), roughness);
}

float GeometrySchlickGGX(float cosTheta, float roughness) {
    float r = (roughness + 1.0);
    float k = (roughness * roughness) / 8.0;

    float numerator = cosTheta;
    float denominator = cosTheta * (1.0 - k) + k;

    return numerator / max(denominator, 0.001);
}

vec3 FresnelSchlick(float cosTheta, vec3 baseReflectivity) {
    return max(baseReflectivity + (1.0 - baseReflectivity) * pow(2, (-5.55473 * cosTheta - 6.98316) * cosTheta), 0.0);
}