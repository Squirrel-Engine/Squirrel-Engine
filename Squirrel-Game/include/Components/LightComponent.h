#pragma once
#include "Macros.h"
#include <iostream>
#include "../../Squirrel-Engine/include/DynamicLightManager.h"
#include "../../Squirrel-Engine/include/LightObject.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()

class LightComponent : public ActorComponent
{
private:
	LightObject* m_Light;
public:
	ELightType m_Type;

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
