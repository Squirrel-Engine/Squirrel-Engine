#include "Skeleton.h"


Skeleton::Skeleton()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent("transformComponent", transformComponent);

	auto renderComponent = new RenderComponent();
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	insertComponent("renderComponent", renderComponent);

	auto audioComponent = new AudioComponent();
	audioComponent->setParent(this);
	this->audioComponent = audioComponent;
	insertComponent("audioComponent", audioComponent);
}

void Skeleton::BeginPlay()
{
	//audioComponent->play();
}

void Skeleton::Update()
{
	transformComponent->rotationY += 0.05;
}
