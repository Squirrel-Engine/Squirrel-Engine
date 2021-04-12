#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "UniformDesc.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

class DrawCall
{
public:
	DrawCall(Model* model, Shader* shader, Squirrel::UNIFORM_DESC uniformDesc);
	//void Draw(){setUniforms(); model.draw();}
	Model* model;
	Shader* shader;
	Squirrel::UNIFORM_DESC uniformDesc;
//private: 
	//void setUniforms();
};

