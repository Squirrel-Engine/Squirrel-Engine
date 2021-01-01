#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
	class RenderObject
	{
	public:
		RenderObject() {}
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<Shader> shader;
		std::shared_ptr<Texture> texture;
		//std::unique_ptr<VertexBuffer> indexBuffer;
	};