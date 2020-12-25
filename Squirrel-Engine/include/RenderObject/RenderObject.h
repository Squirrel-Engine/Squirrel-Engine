#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Texture.h"

class RenderObject
{
public:
	RenderObject(const void* data, unsigned int size, const std::string& shaderPath, const std::string& texturePath);
	VertexArray*		vertexArray;
	VertexBufferLayout* layout;
	VertexBuffer*		vertexBuffer;
	Shader*				shader;
	Texture*			texture;
};