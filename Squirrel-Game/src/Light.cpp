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
	insertComponent("transformComponent", lightComponent);

	RenderComponent* renderComponent = new RenderComponent();
	renderComponent->C_ModelID = 0;
	renderComponent->C_MaterialID_0 = 0;
	renderComponent->C_ShaderID = 0;
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	this->renderComponent->setup();
	insertComponent("renderComponent", renderComponent);
}

void Light::BeginPlay()
{
}

void Light::Update()
{

}