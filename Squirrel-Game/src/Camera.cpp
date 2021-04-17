#include "Camera.h"

Camera::Camera()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	auto cameraComponent = new CameraComponent();
	cameraComponent->setParent(this);
	this->cameraComponent = cameraComponent;
	this->cameraComponent->setup();
	insertComponent("cameraComponent", cameraComponent);
}

void Camera::BeginPlay()
{
}

void Camera::Update()
{
}
