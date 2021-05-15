#include "Components/LightComponent.h"

LightComponent::LightComponent(LightType type)
{
	switch (type)
	{
	case LightType::PointLight:
		light = new PointLight(10.0f, glm::vec3(100.0f, 100.0f, 100.0f), 30.0f, glm::vec3(0.0f, 0.0f, 10.0f));
		getInterface<GM_Interface>().lightManager->addPointLight((PointLight*)light);
		break;
	default:
		break;
	}
}

void LightComponent::BeginPlay()
{

}

void LightComponent::Update()
{

}

void LightComponent::setup()
{

}
