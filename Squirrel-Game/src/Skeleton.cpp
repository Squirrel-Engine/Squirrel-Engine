#include "Skeleton.h"


Skeleton::Skeleton()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent(transformComponent);

	auto renderComponent = new RenderComponent();
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	insertComponent(renderComponent);

	auto audioComponent = new AudioComponent();
	audioComponent->setParent(this);
	this->audioComponent = audioComponent;
	insertComponent(audioComponent);
}

void Skeleton::BeginPlay()
{
	//audioComponent->play();
}

void Skeleton::Update()
{
	transformComponent->rotationY += 2;
	/*for (int i =0; i<1000000; i++)
	{

	}*/
}
