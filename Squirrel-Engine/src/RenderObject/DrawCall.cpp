#include "DrawCall.h"

DrawCall::DrawCall(const std::string& modelPath, const std::string& shaderPath, const std::string& texturePath) {
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Mesh> model;
	std::shared_ptr<Texture> texture;

	model.reset(new Mesh(modelPath));
	shader.reset(new Shader(shaderPath));
	texture.reset(new Texture(texturePath));

	shader->use();
	texture->bind(0);

	shader->setInt("material.diffuse", 0);
	
	this->shader = shader;
	this->model = model;
	this->texture = texture;
}