#shader vertex
#version 330 core
//VertexShader
//////////////
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec3 FragPos;
out vec2 TexCoords;

uniform mat4 viewProjection;
uniform mat4 model;
uniform vec3 viewPos;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoords = aTexCoords;

    gl_Position = viewProjection * model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core
//FragmentShader
////////////////
out vec4 FragColor;
in vec3 FragPos;
in vec2 TexCoords;

uniform sampler2D texture_diffuse;

void main()
{
    float gamma = 2.2f;

    vec3 result = texture(texture_diffuse, TexCoords).rgb;
    result = pow(result, vec3(1.0f / gamma));

    FragColor = vec4(result, 1.0);
}