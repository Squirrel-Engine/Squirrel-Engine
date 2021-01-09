#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

	class DrawCall
	{
	public:
		DrawCall();
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;

		std::shared_ptr<Shader> shader;
		std::shared_ptr<Texture> texture;
		//std::unique_ptr<VertexBuffer> indexBuffer;
	};