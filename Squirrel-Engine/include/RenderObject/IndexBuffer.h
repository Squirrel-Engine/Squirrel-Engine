#pragma once
#include "glad/glad.h"
class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer(const void* data, unsigned int size);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() { return m_Count; }
};