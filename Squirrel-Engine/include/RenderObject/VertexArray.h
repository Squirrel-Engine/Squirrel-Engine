#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();
	
	void add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void bind() const;
	void unnbind() const;
};

