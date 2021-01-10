#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 viewProjection;

void main()
{
	gl_Position = viewProjection * model * vec4(aPos, 1.0f);
}

#shader fragment
#version 330 core
out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0f);
}
