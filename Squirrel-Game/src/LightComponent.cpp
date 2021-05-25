#include "Components/LightComponent.h"

LightComponent::LightComponent()
	: m_Type(ELightType::PointLight)
{

}

void LightComponent::BeginPlay()
{

}

void LightComponent::Update()
{
	vec3 lightPosition = getComponentInParent<TransformComponent>()->getPosition();
	switch (m_Type)
	{
	case ELightType::PointLight:
		dynamic_cast<PointLight*>(m_Light)->m_Position = lightPosition;
		break;
	default:
		break;
	}
}

void LightComponent::setup()
{
	vec3 lightPosition = getComponentInParent<TransformComponent>()->getPosition();
	switch (m_Type)
	{
	case ELightType::DirectionalLight:
		m_Light = new DirectionalLight();
		DynamicLightManager::addDirectionalLight((DirectionalLight*)m_Light);
		break;
	case ELightType::PointLight:
		m_Light = new PointLight(lightPosition);
		DynamicLightManager::addPointLight((PointLight*)m_Light);
		break;
	default:
		break;
	}
}

void LightComponent::setLightType(ELightType type)
{
	m_Type = type;
}
