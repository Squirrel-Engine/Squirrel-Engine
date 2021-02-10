#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

	class DrawCall
	{
	public:
		DrawCall(){}
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<Shader> shader;
		//std::unique_ptr<VertexBuffer> indexBuffer;
	};