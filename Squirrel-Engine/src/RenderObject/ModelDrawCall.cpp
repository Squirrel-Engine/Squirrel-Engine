#include "ModelDrawCall.h"

ModelDrawCall::ModelDrawCall(Model* model, Shader* shader, Squirrel::TRANSFORM_DESC* uniformDesc)
{
	this->model = model;
	this->shader = shader;
	this->uniformDesc = uniformDesc;
}

void ModelDrawCall::draw() {
	model->Draw(*this->shader, *this->uniformDesc);
}