#pragma once
#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"
#include "Components/AudioComponent.h"
#include "Components/AIComponent.h"

SR_ACTOR()

class Skeleton : public Actor
{
public:
	Skeleton();
	void BeginPlay() override;
	void Update() override;

	SR_VAR_START()
	int health;
	int attackPower;
	SR_VAR_END()

	SR_COMP_START()
	TransformComponent transformComponent;
	RenderComponent renderComponent;
	AudioComponent audioComponent;
	SR_COMP_END()
};

SR_ACTOR()
