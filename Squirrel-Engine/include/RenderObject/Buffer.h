#pragma once
class VertexBuffer
{
public:
	virtual ~VertexBuffer() {}

	virtual void bind() const = 0;
	virtual void unbind() const = 0;

	static VertexBuffer* Create(const void* data, unsigned int size);
};

class IndexBuffer
{
public:
	virtual ~IndexBuffer() {}

	virtual void bind() const = 0;
	virtual void unbind() const = 0;

	static IndexBuffer* Create(const void* data, unsigned int size);
};
