#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texCoord;
out vec3 v_color;
out vec2 v_texCoord;

void main()
{
	gl_Position = vec4(position, 1.0f);
	v_color = color;
	v_texCoord = texCoord;
};

#shader fragment
#version 330 core
in vec3 v_color;
in vec2 v_texCoord;

out vec4 color;
uniform sampler2D u_Texture;
void main()
{
	vec4 texColor = texture(u_Texture, v_texCoord);
	//color = vec4(v_color, 1.0f);
	color = texColor;
};
