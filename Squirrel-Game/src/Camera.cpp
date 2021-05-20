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
	//move(vec3(0.002, 0.002, 0));
}

void Camera::move(const vec3& direction){
	transformComponent.translate(direction);
}