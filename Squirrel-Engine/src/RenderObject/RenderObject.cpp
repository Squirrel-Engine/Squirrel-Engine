#include "include/RenderObject/RenderObject.h"

RenderObject::RenderObject(const void* data, unsigned int size, const std::string& shaderPath)
{
	vb = new VertexBuffer(data, size);
	va = new VertexArray();
	shader = new Shader(shaderPath);
	layout = new VertexBufferLayout();
	layout->Push<float>(3);
	layout->Push<float>(3);
	va->add_buffer(*vb, *layout);
}
