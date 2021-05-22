#pragma once
#include "../../Squirrel-Engine/include/Actor.h"
#include "Components/RenderComponent.h"
#include "Macros.h"
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

SR_COMPONENT()

class TransformComponent : public ActorComponent
{
struct Transform {
	vec3 position;
	vec3 rotation;
	vec3 scale;
};
private:
	Transform transform;
public:
	mat4 transformMat;
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

	vec3 getTransform();
	vec3 getRotation();
	vec3 getScale();
	void setTransform(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);
};

SR_COMPONENT()
