#pragma once
#include "Macros.h"
#include "../../Squirrel-Engine/include/Actor.h"
#include "Components/TransformComponent.h"
#include "Components/LightComponent.h"

SR_ACTOR()

class Light : public Actor
{
public:
	Light();
	void BeginPlay() override;
	void Update() override;

	SR_VAR_START()

	SR_VAR_END()

	SR_COMP_START()
	TransformComponent transformComponent;
	LightComponent lightComponent;
	SR_COMP_END()
};

SR_ACTOR()
