#include "Components/TransformComponent.h"

TransformComponent::TransformComponent()
{
	transformMat = mat4(1.0f);
}

void TransformComponent::BeginPlay()
{
}

void TransformComponent::Update()
{
	transform = vec3(positionX, positionY, positionZ);
	transformMat = mat4(1.0f);
	transformMat = translate(transformMat, transform);
	transformMat = glm::rotate(transformMat, radians(rotationX), vec3(1, 0, 0)); //rotation x 
	transformMat = glm::rotate(transformMat, radians(rotationY), vec3(0, 1, 0)); //rotation y
	transformMat = glm::rotate(transformMat, radians(rotationZ), vec3(0, 0, 1)); //rotation z 
	transformMat = scale(transformMat, vec3(scaleX, scaleY, scaleZ));

	dynamic_cast<TRANSFORM_DESC*>(uniform)->model = transformMat;
}

void TransformComponent::setup()
{
	uniform = new TRANSFORM_DESC();
}

vec3& TransformComponent::getTransform()
{
	return transform;
}

vec3 TransformComponent::getRotation()
{
	return vec3(rotationX, rotationY, rotationZ);
}


vec3 TransformComponent::getScale()
{
	return vec3(scaleX, scaleY, scaleZ);
}

void TransformComponent::setTransform(float x, float y, float z)
{
	positionX = x;
	positionY = y;
	positionZ = z;
}

void TransformComponent::setRotation(float x, float y, float z)
{
	rotationX = x;
	rotationY = y;
	rotationZ = z;
}

void TransformComponent::setScale(float x, float y, float z)
{
	scaleX = x;
	scaleY = y;
	scaleZ = z;
}
