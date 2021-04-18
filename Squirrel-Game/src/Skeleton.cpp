#include "Skeleton.h"


Skeleton::Skeleton()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);


	auto skeleton_renderComponent = new RenderComponent();
	skeleton_renderComponent->setParent(this);
	renderComponent = skeleton_renderComponent;
	insertComponent("renderComponent", skeleton_renderComponent);

	AudioComponent* audioComponent = new AudioComponent();

	audioComponent->C_AudioSourceID = 0;
	audioComponent->setParent(this);
	audioComponent = audioComponent;
	insertComponent("audioComponent", audioComponent);
	audioComponent->play();
}

void Skeleton::BeginPlay()
{
}

void Skeleton::Update()
{
	transformComponent->rotationY += 5;
}
