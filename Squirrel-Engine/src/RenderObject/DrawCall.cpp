#include "DrawCall.h"
#include "InterfaceFactory.h"
/*
 * Modelleri önceden belleğe yükleyip öyle çağıralım
 */

// 
DrawCall::DrawCall(const Model& model, const Shader& shader) {
	this->shader = shader;
	this->model = model;
}