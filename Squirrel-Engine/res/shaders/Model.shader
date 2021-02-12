#shader vertex
#version 330 core
///Vertex Shader
////////////////
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;
layout(location = 3) in vec3 aIndex;

out vec3 FragPos;
out vec2 TexCoord;
out vec3 Normal;

uniform mat4 model;
uniform mat4 viewProjection;

void main()
{
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
	FragPos = vec3(model * vec4(aPos, 1.0));
	gl_Position = viewProjection * vec4(FragPos, 1.0);
}

#shader fragment
#version 330 core
///Fragment Shader
//////////////////
out vec4 FragColor;

struct Material {
	sampler2D diffuse;
};

struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 FragPos;
in vec2 TexCoord;
in vec3 Normal;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoord).rgb;

    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoord).rgb;

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
    vec3 specular = light.specular * spec;


	vec3 result = ambient + diffuse + specular;
	FragColor = texture(material.diffuse, TexCoord);
}