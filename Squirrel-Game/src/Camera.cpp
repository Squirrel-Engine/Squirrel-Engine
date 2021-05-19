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
}
