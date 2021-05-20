#pragma once
#include "Macros.h"
#include <glm/glm.hpp>
#include "../../Squirrel-Engine/include/Actor.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
SR_ACTOR()

class Camera : public Actor
{
public:
	Camera();
	void BeginPlay() override;
	void Update() override;
	void move(const vec3& direction);
	SR_VAR_START()

	SR_VAR_END()

	SR_COMP_START()
	TransformComponent transformComponent;
	CameraComponent cameraComponent;
	SR_COMP_END()
};

SR_ACTOR()
