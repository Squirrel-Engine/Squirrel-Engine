#include "DrawCall.h"
#include "InterfaceFactory.h"
/*
 * Modelleri önceden belleğe yükleyip öyle çağıralım
 */

// 
DrawCall::DrawCall(Model* model,  Shader* shader)
{
	this->model = model;
	this->shader = shader;
}
