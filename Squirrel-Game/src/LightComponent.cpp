#include "Components/LightComponent.h"

LightComponent::LightComponent(ELightType type)
	:m_Type(type)
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
		getInterface<GM_Interface>().lightManager->addPointLight((PointLight*)m_Light);
		break;
	default:
		break;
	}
}
