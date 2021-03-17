#shader vertex
#version 330 core
///Vertex Shader
////////////////
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 viewProjection;

void main()
{
	FragPos = vec3(model * vec4(aPos, 1.0));
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    Normal = mat3(transpose(inverse(model))) * aNormal;

    gl_Position = viewProjection * vec4(FragPos, 1.0);
}

#shader fragment
#version 330 core
///Fragment Shader
//////////////////

out vec4 FragColor;
in vec2 TexCoord

uniform sampler texture_diffuse1
void main()
{ 
    FragColor = vec4(texture(texture_diffuse, TexCoord).rgb,1.0);
}