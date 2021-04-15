#include "LightDrawCall.h"

LightDrawCall::LightDrawCall(Squirrel::Light* light, Shader* shader, Squirrel::TRANSFORM_DESC* transformUniform, Squirrel::LIGHT_DESC* lightUniform)
{
	this->light = light;
	this->shader = shader;
	this->transformUniform = transformUniform;
	this->lightUniform = lightUniform;
}

void LightDrawCall::draw() {
	light->Draw(*this->shader, *this->transformUniform, *this->lightUniform);
}