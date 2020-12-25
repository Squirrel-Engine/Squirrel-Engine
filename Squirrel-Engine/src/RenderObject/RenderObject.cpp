#include "include/RenderObject/RenderObject.h"

RenderObject::RenderObject(const void* data, unsigned int size, const std::string& shaderPath, const std::string& texturePath)
{
	vertexBuffer = new VertexBuffer(data, size);
	vertexArray = new VertexArray();
	shader = new Shader(shaderPath);
	texture = new Texture(texturePath);
	layout = new VertexBufferLayout();
	layout->Push<float>(3);
	layout->Push<float>(2);
	vertexArray->add_buffer(*vertexBuffer, *layout);
}
