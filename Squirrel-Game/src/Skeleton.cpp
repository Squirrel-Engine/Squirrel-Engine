#include "Skeleton.h"


Skeleton::Skeleton()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	auto skeleton_transformComponent = new TransformComponent();
	skeleton_transformComponent->setParent(this);
	transformComponent = skeleton_transformComponent;
	insertComponent("transformComponent", skeleton_transformComponent);

	auto skeleton_renderComponent = new RenderComponent();
	skeleton_renderComponent->setParent(this);
	renderComponent = skeleton_renderComponent;

	insertComponent("renderComponent", skeleton_renderComponent);
}

void Skeleton::BeginPlay()
{
}

void Skeleton::Update()
{
	transformComponent->rotationY += 5;
}
