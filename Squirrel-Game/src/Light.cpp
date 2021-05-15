#include "Light.h"

Light::Light(LightType type)
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent("transformComponent", transformComponent);

	auto lightComponent = new LightComponent(type);
	lightComponent->setParent(this);
	this->lightComponent = lightComponent;
	insertComponent("lightComponent", lightComponent);
}

void Light::BeginPlay()
{

}

void Light::Update()
{

}
