#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
class RenderObject
{
public:
	RenderObject(const void* data, unsigned int size, const std::string& shaderPath);
	VertexArray*		va;
	VertexBufferLayout* layout;
	VertexBuffer*		vb;
	Shader*				shader;
};
