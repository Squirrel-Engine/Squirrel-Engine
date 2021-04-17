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
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->constant = 1.0f;
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->linear = 0.14f;
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->quadratic = 0.07f;
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->lightColor = color;
	dynamic_cast<Squirrel::LIGHT_DESC*>(uniform)->lightPos = getComponent<TransformComponent*>("transformComponent")->getTransform();

	auto drawCall = new LightDrawCall(	&light,
										getInterface<RM_Interface>().getShader(shaderID),
										dynamic_cast<Squirrel::TRANSFORM_DESC*>(getComponent<TransformComponent*>("transformComponent")->uniform),
										dynamic_cast<Squirrel::LIGHT_DESC*>(uniform));
	InterfaceFactory::getInstance().getRDInterface().submitDrawCall(*drawCall);
}

void LightComponent::setup()
{
	uniform = new Squirrel::LIGHT_DESC();
}

void LightComponent::setColor(float r, float g, float b) {
	glm::vec3 color(r, g, b);
	this->color = color;
}