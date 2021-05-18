#pragma once
#include "Macros.h"
#include <iostream>
#include "../../Squirrel-Engine/include/LightObject.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"
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
	LightComponent(ELightType type);
	void BeginPlay() override;
	void Update() override;
	void setup() override;
};

SR_COMPONENT()
