#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 aColor;
out vec3 ourColor;

void main()
{
	gl_Position = vec4(position, 1.0f);
	ourColor = aColor;
};

#shader fragment
#version 330 core

out vec4 color;

void main()
{
	color = vec4(1.0f, 1.0f, 0.0f, 1.0f);
};
