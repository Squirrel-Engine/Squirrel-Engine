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

}

void LightComponent::setup()
{
	vec3 lightPosition = getComponentInParent<TransformComponent>()->getTransform();
	switch (m_Type)
	{
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
