#pragma once
#include "Shader.h"
#include "UniformDesc.h"
#include "Model.h"
#include "DrawCall.h"

class ModelDrawCall : public DrawCall
{
public:
	ModelDrawCall(Model* model, Shader* shader, TRANSFORM_DESC* uniformDesc);
	void draw() override;

private:
	Model* model;
	Shader* shader;
	TRANSFORM_DESC* uniformDesc;
};
