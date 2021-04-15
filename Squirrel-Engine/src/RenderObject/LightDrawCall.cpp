#include "LightDrawCall.h"

LightDrawCall::LightDrawCall(Shader* shader, Squirrel::LIGHT_DESC* uniformDesc)
{
	this->shader = shader;
	this->uniformDesc = uniformDesc;
}

void LightDrawCall::draw() {
	
}