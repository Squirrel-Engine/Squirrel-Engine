#pragma once
#include "DynamicLightManager.h"
#include "LightObject.h"
#include "InterfaceFactory.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()

class LightComponent : public ActorComponent
{
private:
	TransformComponent* m_Transform;
	ELightType m_Type;
public:
	SR_VAR_START()
	LightObject* m_Light;
	SR_VAR_END()
public:
	LightComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;
	void setLightType(ELightType type);
};

SR_COMPONENT()
