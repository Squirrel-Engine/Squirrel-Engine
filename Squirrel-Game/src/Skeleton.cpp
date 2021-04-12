#include "Skeleton.h"

Skeleton::Skeleton()
{
	health = 100;
	attackPower = 50;


	TransformComponent* skeleton_transformComponent = new TransformComponent();
	skeleton_transformComponent->setParent(this);
	transformComponent = skeleton_transformComponent;
	transformComponent->setup();
	insertComponent("transformComponent", skeleton_transformComponent);

	RenderComponent* skeleton_renderComponent = new RenderComponent();
	skeleton_renderComponent->C_ModelID = 0;
	skeleton_renderComponent->C_MaterialID_0 = 0;
	skeleton_renderComponent->C_MaterialID_1 = 1;
	skeleton_renderComponent->C_ShaderID = 0;
	skeleton_renderComponent->setParent(this);
	renderComponent = skeleton_renderComponent;
	renderComponent->setup();
	insertComponent("renderComponent", skeleton_renderComponent);
}

void Skeleton::BeginPlay()
{
}

void Skeleton::Update()
{
	transformComponent->getComponent<TransformComponent*>("transformComponent")->rotationY += 5;
}
