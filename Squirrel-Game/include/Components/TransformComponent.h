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
class 	TransformComponent : public ActorComponent
{
private:
	glm::vec3 transform;
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

	
	glm::vec3& getTransform();
	glm::vec3 getRotation();
  
	glm::vec3 getScale();
	void setTransform(glm::vec3 vector);
	void setRotation(glm::vec3 vector);
	void setScale(glm::vec3 vector);

};
SR_COMPONENT()