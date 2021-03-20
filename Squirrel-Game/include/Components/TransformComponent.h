#pragma once

#include "../../Squirrel-Engine/include/Actor.h"
#include "Macros.h"
#include <iostream>
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
SR_COMPONENT()
class 	TransformComponent : public Squirrel::ActorComponent
{
private:
	glm::mat4 transformMat;
	SR_VAR_START()
		float transformX = 5;
		float transformY = 0;
		float transformZ = 0;

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
	void setTransform(glm::vec3 vector);
	void setRotation(glm::vec3 vector);
	
};
SR_COMPONENT()