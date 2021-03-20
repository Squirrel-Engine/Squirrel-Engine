#include "Components/TransformComponent.h"



TransformComponent::TransformComponent()
{
	transformMat = glm::mat3(1.0f);
}

void TransformComponent::BeginPlay()
{
}

void TransformComponent::Update()
{
	transformMat = glm::translate(transformMat, glm::vec3(transformX, transformY, transformZ));
	//transformMat = glm::rotate();
	//transformMat = glm::scale();

}

void TransformComponent::setup()
{
}

glm::vec3 TransformComponent::getTransform()
{
	return glm::vec3(transformX, transformY, transformZ);
}

glm::vec3 TransformComponent::getRotation()
{
	return glm::vec3(rotationX, rotationY, rotationZ);
}

void TransformComponent::setTransform(glm::vec3 vector)
{
	transformX = vector.x;
	transformY = vector.y;
	transformZ = vector.z;
}

void TransformComponent::setRotation(glm::vec3 vector)
{
	rotationX = vector.x;
	rotationY = vector.y;
	rotationZ = vector.z;
}
