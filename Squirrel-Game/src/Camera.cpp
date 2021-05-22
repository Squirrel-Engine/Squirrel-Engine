#include "Camera.h"

Camera::Camera()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent(transformComponent);

	auto cameraComponent = new CameraComponent();
	cameraComponent->setParent(this);
	this->cameraComponent = cameraComponent;
	insertComponent(cameraComponent);
}

void Camera::BeginPlay()
{
}

void Camera::Update()
{
}
