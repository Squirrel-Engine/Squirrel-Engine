#include "Light.h"

Light::Light() {
	TransformComponent* transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	LightComponent* lightComponent = new LightComponent();
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