#shader vertex
#version 330 core
///Vertex Shader
////////////////
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_text_coords;
layout(location = 3) in ivec4 bone_ids;     // INT pointer
layout(location = 4) in vec4 weights;

out vec2 text_coords;
out vec3 normal;
out vec3 frag_pos;

uniform mat4 MVP;
uniform mat4 M_matrix;
uniform mat4 normals_matrix;

const int MAX_BONES = 100;
uniform mat4 bones[MAX_BONES];

void main()
{
	mat4 bone_transform = bones[bone_ids[0]] * weights[0];
	bone_transform += bones[bone_ids[1]] * weights[1];
	bone_transform += bones[bone_ids[2]] * weights[2];
	bone_transform += bones[bone_ids[3]] * weights[3];

	vec4 boned_position = bone_transform * vec4(in_position, 1.0); // transformed by bones

	normal = normalize(vec3(normals_matrix * (bone_transform * vec4(in_normal, 0.0))));

	frag_pos = vec3(M_matrix * boned_position);
	text_coords = in_text_coords;

	gl_Position = MVP * boned_position;
}

#shader fragment
#version 330 core
///Fragment Shader
//////////////////
in vec2 text_coords;
in vec3 frag_pos;
in vec3 normal;

struct Material
{
	sampler2D texture_diffuse1;

	sampler2D texture_specular1;

	float shininess;
	float transparency;
};

struct PointLight
{
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform Material material;
uniform PointLight point_light;
uniform vec3 view_pos;


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 view_dir, vec3 frag_pos)
{
	vec3 light_dir = normalize(light.position - frag_pos);
	//Diffuse
	float diff = max(dot(normal, light_dir), 0.0);
	//Specular 
	vec3 reflect_dir = reflect(-light_dir, normal);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
	//Attenuation
	float distance = length(light.position - frag_pos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, text_coords));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.texture_diffuse1, text_coords));
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, text_coords));


	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);
}

void main()
{
	vec3 view_dir = normalize(view_pos - frag_pos);

	vec4 calc_color = vec4(CalcPointLight(point_light, normal, view_dir, frag_pos), 1.0);
	calc_color.a *= 1;

	gl_FragColor = calc_color;

}