#include "Components/LightComponent.h"

LightComponent::LightComponent(LightType type)
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
	vec3 lightPosition = getComponent<TransformComponent>()->getTransform();
	switch (m_Type)
	{
	case LightType::PointLight:
		m_Light = new PointLight(lightPosition);
		getInterface<GM_Interface>().lightManager->addPointLight((PointLight*)m_Light);
		break;
	default:
		break;
	}
}
