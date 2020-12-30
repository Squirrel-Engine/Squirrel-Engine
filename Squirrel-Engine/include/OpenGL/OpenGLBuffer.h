#pragma once
#include "include/RenderObject/Buffer.h"
#include "glad/glad.h"

class OpenGLVertexBuffer : public VertexBuffer {
public:
	OpenGLVertexBuffer(const void* data, unsigned int size);
	virtual ~OpenGLVertexBuffer();

	virtual void bind() const;
	virtual void unbind() const;
private:
	unsigned int m_RendererID;
};

class OpenGLIndexBuffer : public IndexBuffer {
public:
	OpenGLIndexBuffer(const void* data, unsigned int size);
	virtual ~OpenGLIndexBuffer();

	virtual void bind() const;
	virtual void unbind() const;
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
};