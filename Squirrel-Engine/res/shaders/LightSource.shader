#shader vertex
#version 330 core
//VertexShader
//////////////
layout (location = 0) in vec3 aPos;

uniform mat4 viewProjection;
uniform mat4 model;

void main()
{
    gl_Position = viewProjection * model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core
//FragmentShader
////////////////

uniform vec3 lightColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(lightColor, 1.0);
}