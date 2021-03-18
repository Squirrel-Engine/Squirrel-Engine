#include "Components/TransformComponent.h"



TransformComponent::TransformComponent()
{
	
}

void TransformComponent::BeginPlay()
{
}

void TransformComponent::Update()
{
	transformMat = glm::translate(transformMat, glm::vec3(transformX, transformY, transformZ));
	//transformMat = glm::rotate();
	//transformMat = glm::scale();
	std::cout << "TRANSFORM COMPONENT TEST ULAN" << std::endl;
}

void TransformComponent::setup()
{
}

glm::vec3 TransformComponent::getTransform()
{
	return glm::vec3(transformX, transformY, transformZ);
}

void TransformComponent::setTransform(glm::vec3 vector)
{
	transformX = vector.x;
	transformY = vector.y;
	transformZ = vector.z;
}
