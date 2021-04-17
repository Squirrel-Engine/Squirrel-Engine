#include "Components/CameraComponent.h"

CameraComponent::CameraComponent()
{
	m_ViewportHeight = Configuration::getInstance().renderConfig.screenHeight;
	m_ViewportWidth = Configuration::getInstance().renderConfig.screenWidth;

	updateProjection();
}

void CameraComponent::BeginPlay()
{
}

void CameraComponent::Update()
{
	updateView();
	cameraDesc->viewPos = *m_Position;
	cameraDesc->viewProjection = getViewProjection();
}

void CameraComponent::setup()
{
	m_Position = &getComponent<TransformComponent*>("transformComponent")->getTransform();
}

void CameraComponent::updateProjection()
{
	m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
	m_Projection = perspective(radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void CameraComponent::updateView()
{
	quat orientation = getOrientation();
	m_ViewMatrix = translate(mat4(1.0f), *m_Position) * toMat4(orientation);
	m_ViewMatrix = inverse(m_ViewMatrix);
}

vec3 CameraComponent::getUpDirection() const
{
	return glm::rotate(getOrientation(), vec3(0.0f, 1.0f, 0.0f));
}

vec3 CameraComponent::getRightDirection() const
{
	return glm::rotate(getOrientation(), vec3(1.0f, 0.0f, 0.0f));
}

vec3 CameraComponent::getForwardDirection() const
{
	return glm::rotate(getOrientation(), vec3(0.0f, 0.0f, -1.0f));
}

quat CameraComponent::getOrientation() const
{
	return quat(vec3(-m_Pitch, -m_Yaw, 0.0f));
}
