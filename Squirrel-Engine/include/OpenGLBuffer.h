#pragma once
#include "include/Buffer.h"
#include "glad/glad.h"

class OpenGLVertexBuffer : public VertexBuffer {
public:
	OpenGLVertexBuffer(const void* data, unsigned int size);
	virtual ~OpenGLVertexBuffer();

	virtual void bind() const override;
	virtual void unbind() const override;

	virtual const BufferLayout& getLayout() const override { return m_Layout; }
	virtual void setLayout(const BufferLayout& layout) override { m_Layout = layout; }
private:
	unsigned int m_RendererID;
	BufferLayout m_Layout;
};

class OpenGLIndexBuffer : public IndexBuffer {
public:
	OpenGLIndexBuffer(const void* data, unsigned int size);
	virtual ~OpenGLIndexBuffer();

	virtual void bind() const override;
	virtual void unbind() const override;
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
};