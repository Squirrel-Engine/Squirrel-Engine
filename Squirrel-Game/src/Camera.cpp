#include "Camera.h"

Camera::Camera()
{
	bindComponent(&transformComponent);
	bindComponent(&cameraComponent);
}

void Camera::BeginPlay()
{
}

void Camera::Update()
{
	//transformComponent.translate(0, 0, 0.01);
	transformComponent.rotate(0, 0.001, 0);
}