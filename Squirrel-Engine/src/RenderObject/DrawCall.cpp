#include "DrawCall.h"
#include "InterfaceFactory.h"
/*
 * Modelleri önceden belleğe yükleyip öyle çağıralım
 */

// 
DrawCall::DrawCall(Model* model,  Shader* shader, Squirrel::UNIFORM_DESC uniformDesc)
{
	this->model = model;
	this->shader = shader;
	this->uniformDesc = uniformDesc;
}
