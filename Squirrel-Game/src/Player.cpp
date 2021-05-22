#include "Player.h"


Player::Player()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent("transformComponent", transformComponent);

	auto renderComponent = new RenderComponent();
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	insertComponent("renderComponent", renderComponent);

}

void Player::BeginPlay()
{
	//audioComponent->play();
}

void Player::Update()
{
	transformComponent->rotationY += 0.05;
}
