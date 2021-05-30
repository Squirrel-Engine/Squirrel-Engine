#include "Components/TransformComponent.h"

TransformComponent::TransformComponent()
{
	transform.position = vec3(0, 0, 0);
	transform.rotation = vec3(0, 0, 0);
	transform.scale = vec3(1, 1, 1);
}

void TransformComponent::BeginPlay()
{
}

void TransformComponent::Update()
{
	transformMat = mat4(1.0f);
	transformMat = glm::translate(transformMat, transform.position);
	transformMat = glm::rotate(transformMat, radians(transform.rotation.x), vec3(1, 0, 0)); //rotation x 
	transformMat = glm::rotate(transformMat, radians(transform.rotation.y), vec3(0, 1, 0)); //rotation y
	transformMat = glm::rotate(transformMat, radians(transform.rotation.z), vec3(0, 0, 1)); //rotation z 
	transformMat = glm::scale(transformMat, transform.scale);

	orientation = getOrientation();
	up = glm::rotate(orientation, glm::vec3(0.0f, 1.0f, 0.0f));
	forward = glm::rotate(orientation, glm::vec3(0.0f, 0.0f, -1.0f));
	right = glm::rotate(orientation, glm::vec3(1.0f, 0.0f, 0.0f));

	dynamic_cast<TRANSFORM_DESC*>(uniforms)->model = transformMat;
	
}

void TransformComponent::setup()
{
	uniforms = new TRANSFORM_DESC();
}

void TransformComponent::translate(const vec3& direction)
{
	transform.position += direction;
}

void TransformComponent::translate(float x, float y, float z)
{
	transform.position.x += x;
	transform.position.y += y;
	transform.position.z += z;
}

void TransformComponent::rotate(const vec3& eulers)
{
	transform.rotation += eulers;
}

void TransformComponent::rotate(float x, float y, float z)
{
	transform.rotation.x += x;
	transform.rotation.y += y;
	transform.rotation.z += z;
}

vec3& TransformComponent::getPosition()
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
	transform.position = vec3(x, y, z);
}

void TransformComponent::setRotation(float x, float y, float z)
{
	transform.rotation = vec3(x, y, z);
}

void TransformComponent::setScale(float x, float y, float z)
{
	transform.scale = vec3(x, y, z);
}

glm::quat TransformComponent::getOrientation()
{
	return glm::quat(glm::vec3(-transform.rotation.x, -transform.rotation.y, -transform.rotation.z));
}
