#include "Components/CameraComponent.h"

const float CameraComponent::DEFAULT_FOVX = 90.0f;
const float CameraComponent::DEFAULT_ZNEAR = 0.1f;
const float CameraComponent::DEFAULT_ZFAR = 1000.0f;

const vec3 CameraComponent::WORLD_XAXIS(1.0f, 0.0f, 0.0f);
const vec3 CameraComponent::WORLD_YAXIS(0.0f, 1.0f, 0.0f);
const vec3 CameraComponent::WORLD_ZAXIS(0.0f, 0.0f, 1.0f);

CameraComponent::CameraComponent()
{
	m_ViewportHeight = Configuration::getInstance().renderConfig.screenHeight;
	m_ViewportWidth = Configuration::getInstance().renderConfig.screenWidth;
	m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
	m_FOV = DEFAULT_FOVX;
	m_NearClip = DEFAULT_ZNEAR;
	m_FarClip = DEFAULT_ZFAR;

	updatePerspective(m_FOV, m_AspectRatio, m_NearClip, m_FarClip);
	updateLookAt(m_Position, m_Target, m_Up);
}

void CameraComponent::BeginPlay()
{

}

void CameraComponent::Update()
{
	updateView();
	cameraDesc->viewPos = m_Position;
	cameraDesc->viewProjection = m_Projection * m_ViewMatrix;
}

void CameraComponent::setup()
{

}

void CameraComponent::updatePerspective(float fovx, float aspect, float znear, float zfar)
{
	m_FOV = fovx;
	m_AspectRatio = aspect;
	m_NearClip = znear;
	m_FarClip = zfar;
	m_Projection = glm::perspective(radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void CameraComponent::updateLookAt(const vec3 &eye, const vec3 &target, const vec3 &up)
{
	m_Position = eye;
	m_Target = target;
	m_Up = up;
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Target, m_Up);
}

void CameraComponent::updateView()
{	
	m_Position = getComponentInParent<TransformComponent>()->getPosition();
	glm::quat orientation = getOrientation();
	m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);;
	m_ViewMatrix = glm::inverse(m_ViewMatrix);
}

glm::quat CameraComponent::getOrientation()
{
	m_Rotation = getComponentInParent<TransformComponent>()->getRotation();
	return glm::quat(glm::vec3(-m_Rotation.x, -m_Rotation.y, -m_Rotation.z));
}

void CameraComponent::setViewportSize(float width, float height)
{
	m_ViewportWidth = width;
	m_ViewportHeight = height;
	m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
	updatePerspective(m_FOV, m_AspectRatio, m_NearClip, m_FarClip);
}
