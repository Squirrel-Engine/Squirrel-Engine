#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "UniformDesc.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"
#include "DrawCall.h"

class ModelDrawCall :  public DrawCall
{
public:
	ModelDrawCall(Model* model, Shader* shader, Squirrel::TRANSFORM_DESC* uniformDesc);
	void draw() override;
	
public:
	Model* model;
	Shader* shader;
	Squirrel::TRANSFORM_DESC* uniformDesc;
};
