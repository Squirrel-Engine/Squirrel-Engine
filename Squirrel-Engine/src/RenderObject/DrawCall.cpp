#include "DrawCall.h"
#include "InterfaceFactory.h"
/*
 * Modelleri önceden belleğe yükleyip öyle çağıralım
 */

// 
DrawCall::DrawCall(const std::string& modelPath, Shader& shader) {

	std::shared_ptr<Model> model;
	model.reset(new Model(modelPath));

	shader.use();

	this->shader = shader;
	this->model = model;
}