#include "Components/LightComponent.h"

LightComponent::LightComponent()
{
	shaderID = 1;
	color = glm::vec3(1.0f);
}

void LightComponent::BeginPlay()
{

}

void LightComponent::Update()
{
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->lightPos = getComponent<TransformComponent*>("transformComponent")->getTransform();

	auto drawCall = new LightDrawCall(Squirrel::InterfaceFactory::getInstance().getRMInterface().getShader(shaderID),
								      dynamic_cast<Squirrel::LIGHT_DESC*>(uniform));

	Squirrel::InterfaceFactory::getInstance().getRDInterface().submitDrawCall(*drawCall);
}

void LightComponent::setup()
{
	uniform = new Squirrel::LIGHT_DESC();
}

void LightComponent::setColor(float r, float g, float b) {
	glm::vec3 color(r, g, b);
	this->color = color;
}