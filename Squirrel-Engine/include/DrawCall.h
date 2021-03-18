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
	DrawCall(Model* model, Shader* shader);
	//void Draw(){setUniforms(); model.draw();}
	Model* model;
	Shader* shader;
//private: 
	//void setUniforms();
};

