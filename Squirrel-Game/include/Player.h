#pragma once
#include "Macros.h"
#include "../../Squirrel-Engine/include/Actor.h"
#include "Components/CameraComponent.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"


SR_ACTOR()

class Player : public Actor
{
public:
	Player();
	void BeginPlay() override;
	void Update() override;
	SR_VAR_START()

	SR_VAR_END()
	
	SR_COMP_START()
	RenderComponent* renderComponent;
	TransformComponent* transformComponent;
	CameraComponent* cameraComponent;
	SR_COMP_END()
};

SR_ACTOR()
