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
	
	SR_VAR_END()

public:
	TransformComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	void translate(const vec3& direction);
	void translate(float x, float y, float z);
	void rotate(const vec3& eulers);
	void rotate(float x, float y, float z);

	vec3& getPosition();
	vec3& getRotation();
	vec3& getScale();
	void setTransform(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);
};

SR_COMPONENT()
