#include "Components/LightComponent.h"

LightComponent::LightComponent()
{
	shaderID = 1;
	color = vec3(255.0f);
	intensity = 5.0f;
	attenuationRadius = 20.0f;
}

void LightComponent::BeginPlay()
{
}

void LightComponent::Update()
{
	dynamic_cast<LIGHT_DESC*>(uniform)->position = getComponent<TransformComponent*>("transformComponent")->getTransform();
	dynamic_cast<LIGHT_DESC*>(uniform)->lightColour = color;
	dynamic_cast<LIGHT_DESC*>(uniform)->intensity = intensity;
	dynamic_cast<LIGHT_DESC*>(uniform)->attenuationRadius = attenuationRadius;

	auto drawCall = new LightDrawCall(&light,
	                                  getInterface<RM_Interface>().getShader(shaderID),
	                                  dynamic_cast<TRANSFORM_DESC*>(getComponent<TransformComponent*>("transformComponent")->uniform),
	                                  dynamic_cast<LIGHT_DESC*>(uniform));

	InterfaceFactory::getInstance().getRDInterface().submitDrawCall(*drawCall);
}

void LightComponent::setup()
{
	uniform = new LIGHT_DESC();
}

void LightComponent::setColor(float r, float g, float b)
{
	vec3 color(r, g, b);
	this->color = color;
}
