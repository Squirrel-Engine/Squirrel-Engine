#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

class DrawCall
{
public:
	DrawCall(const std::string& model, const std::string& shader, const std::string& texture);

	std::shared_ptr<Model> model;
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;
};

