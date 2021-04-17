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
	transform = glm::vec3(positionX, positionY, positionZ);
	transformMat = glm::mat4(1.0f);
	transformMat = glm::translate(transformMat, transform);
	transformMat = glm::rotate(transformMat, glm::radians(rotationX), glm::vec3(1, 0, 0));	//rotation x 
	transformMat = glm::rotate(transformMat, glm::radians(rotationY), glm::vec3(0, 1, 0));	//rotation y
	transformMat = glm::rotate(transformMat, glm::radians(rotationZ), glm::vec3(0, 0, 1));	//rotation z 
	transformMat = glm::scale(transformMat, glm::vec3(scaleX, scaleY, scaleZ));

	dynamic_cast<TRANSFORM_DESC*>(uniform)->model = transformMat;
}

void TransformComponent::setup()
{
	uniform = new TRANSFORM_DESC();

}

glm::vec3& TransformComponent::getTransform()
{
	return transform;
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
	glm::vec3 vector(x, y, z);
	positionX = vector.x;
	positionY = vector.y;
	positionZ = vector.z;
}

void TransformComponent::setRotation(float x, float y, float z)
{
	glm::vec3 vector(x, y, z);
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