#pragma once
#include "../../Squirrel-Engine/include/Actor.h"
#include "Macros.h"
#include <iostream>
#include "Components/RenderComponent.h"
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

SR_COMPONENT()
class 	TransformComponent : public Squirrel::ActorComponent
{
private:

public:
	glm::mat4 transformMat;
	SR_VAR_START()
		float positionX = 0;
		float positionY = 0;
		float positionZ = 0;

		float rotationX = 0;
		float rotationY = 0;
		float rotationZ = 0;

		float scaleX = 1;
		float scaleY = 1;
		float scaleZ = 1;
	SR_VAR_END()

public:
	TransformComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	
	glm::vec3 getTransform();
	glm::vec3 getRotation();
	void setTransform(float x, float y, float z);
	void setRotation(float x, float y, float z);
	
};
SR_COMPONENT()