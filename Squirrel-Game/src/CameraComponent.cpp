#include "Components/CameraComponent.h"

const float CameraComponent::DEFAULT_ROTATION_SPEED = 0.3f;
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

	perspective();
	view();
}

void CameraComponent::BeginPlay()
{

}

void CameraComponent::Update()
{
	m_Position = getComponentInParent<TransformComponent>()->getPosition();
	view();
	cameraDesc->viewPos = m_Position;
	cameraDesc->viewProjection = m_Projection * m_ViewMatrix;;
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

void CameraComponent::perspective()
{
	m_Projection = glm::perspective(radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void CameraComponent::updateView(const vec3& eye, const vec3& target, const vec3& up)
{
	m_Position = eye;
	m_Target = target;
	m_Up = up;
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Target, m_Up);
}

void CameraComponent::view()
{
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Target, m_Up);
}

void CameraComponent::setViewportSize(float width, float height)
{
	m_ViewportWidth = width;
	m_ViewportHeight = height;
	m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
	updatePerspective(m_FOV, m_AspectRatio, m_NearClip, m_FarClip);
}