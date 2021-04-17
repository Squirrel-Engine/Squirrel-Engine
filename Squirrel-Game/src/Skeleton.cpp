#include "Skeleton.h"

Skeleton::Skeleton()
{
	TransformComponent* transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	RenderComponent* renderComponent = new RenderComponent();
	renderComponent->C_ModelID = 0;
	renderComponent->C_MaterialID_0 = 0;
	renderComponent->C_MaterialID_1 = 1;
	renderComponent->C_ShaderID = 0;
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	this->renderComponent->setup();
	insertComponent("renderComponent", renderComponent);
}

void Skeleton::BeginPlay()
{
}

void Skeleton::Update()
{
	transformComponent->getComponent<TransformComponent*>("transformComponent")->rotationY += 0.05;
}
