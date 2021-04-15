#include "Camera.h"

Camera::Camera() {
	TransformComponent* transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	this->transformComponent->setup();
	insertComponent("transformComponent", transformComponent);

	CameraComponent* cameraComponent = new CameraComponent();
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