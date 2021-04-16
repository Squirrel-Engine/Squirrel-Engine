#include "Components/TransformComponent.h"

TransformComponent::TransformComponent()
{
	transformMat = glm::mat4(1.0f);
}

void TransformComponent::BeginPlay()
{

}

void TransformComponent::Update()
{
	transformMat = glm::mat4(1.0f);
	transformMat = glm::translate(transformMat, glm::vec3(positionX, positionY, positionZ));
	transformMat = glm::rotate(transformMat, glm::radians(rotationX), glm::vec3(1, 0, 0));	//rotation x 
	transformMat = glm::rotate(transformMat, glm::radians(rotationY), glm::vec3(0, 1, 0));	//rotation y
	transformMat = glm::rotate(transformMat, glm::radians(rotationZ), glm::vec3(0, 0, 1));	//rotation z 
	transformMat = glm::scale(transformMat, glm::vec3(scaleX, scaleY, scaleZ));
}

void TransformComponent::setup()
{
}

glm::vec3 TransformComponent::getTransform()
{
	return glm::vec3(positionX, positionY, positionZ);
}

glm::vec3 TransformComponent::getRotation()
{
	return glm::vec3(rotationX, rotationY, rotationZ);
}

glm::vec3 TransformComponent::getScale()
{
	return glm::vec3(scaleX, scaleY, scaleZ);
}

void TransformComponent::setTransform(glm::vec3 vector)
{
	positionX = vector.x;
	positionY = vector.y;
	positionZ = vector.z;
}

void TransformComponent::setRotation(glm::vec3 vector)
{
	rotationX = vector.x;
	rotationY = vector.y;
	rotationZ = vector.z;
}

void TransformComponent::setScale(glm::vec3 vector)
{
	scaleX = vector.x;
	scaleY = vector.y;
	scaleZ = vector.z;
}