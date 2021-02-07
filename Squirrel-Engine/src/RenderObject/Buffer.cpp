#include "Buffer.h"
#include "OpenGLBuffer.h"

VertexBuffer* VertexBuffer::Create(const void* data, unsigned int size) {
	//TODO: Render API base implementation
	return new OpenGLVertexBuffer(data, size);
}

IndexBuffer* IndexBuffer::Create(const void* data, unsigned int size)
{
	//TODO: Render API base implementation
	return new OpenGLIndexBuffer(data, size);
}
