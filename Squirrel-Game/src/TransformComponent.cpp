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
	transform.position = vec3(positionX, positionY, positionZ);
	transform.rotation = vec3(rotationX, rotationY, rotationZ);
	transform.scale    = vec3(scaleX, scaleY, scaleZ);
	transformMat = mat4(1.0f);
	transformMat = glm::translate(transformMat, transform.position);
	transformMat = glm::rotate(transformMat, radians(transform.rotation.x), vec3(1, 0, 0)); //rotation x 
	transformMat = glm::rotate(transformMat, radians(transform.rotation.y), vec3(0, 1, 0)); //rotation y
	transformMat = glm::rotate(transformMat, radians(transform.rotation.z), vec3(0, 0, 1)); //rotation z 
	transformMat = glm::scale(transformMat, transform.scale);

	dynamic_cast<TRANSFORM_DESC*>(getUniforms())->model = transformMat;
}

void TransformComponent::setup()
{
	setUniforms(TRANSFORM_DESC());
}

vec3& TransformComponent::getTransform()
{
	return transform.position;
}

vec3& TransformComponent::getRotation()
{
	return transform.rotation;
}

vec3& TransformComponent::getScale()
{
	return transform.scale;
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
