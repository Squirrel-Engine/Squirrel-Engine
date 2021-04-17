#include "LightDrawCall.h"

LightDrawCall::LightDrawCall(LightObject* light, Shader* shader, TRANSFORM_DESC* transformUniform, LIGHT_DESC* lightUniform)
{
	this->light = light;
	this->shader = shader;
	this->transformUniform = transformUniform;
	this->lightUniform = lightUniform;
}

void LightDrawCall::draw() {
	light->Draw(*this->shader, *this->transformUniform, *this->lightUniform);
}