#pragma once
#include "Buffer.h"

class VertexArray
{
public:
	virtual ~VertexArray() {};

	virtual void bind() const = 0;
	virtual void unnbind() const = 0;

	virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
	virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

	static VertexArray* Create();
};