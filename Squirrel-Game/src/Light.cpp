#include "Light.h"

Light::Light()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	auto lightComponent = new LightComponent();
	lightComponent->setParent(this);
	this->lightComponent = lightComponent;
	this->lightComponent->setup();
	insertComponent("lightComponent", lightComponent);
}

void Light::BeginPlay()
{
}

void Light::Update()
{
}
