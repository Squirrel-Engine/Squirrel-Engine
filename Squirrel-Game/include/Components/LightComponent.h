#pragma once
#include "Macros.h"
#include <iostream>
#include "DynamicLightManager.h"
#include "LightObject.h"
#include "InterfaceFactory.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()

class LightComponent : public ActorComponent
{
private:
	LightObject* m_Light;
	ELightType m_Type;
public:
	SR_VAR_START()
	
	SR_VAR_END()
public:
	LightComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;
	void setLightType(ELightType type);
};

SR_COMPONENT()
