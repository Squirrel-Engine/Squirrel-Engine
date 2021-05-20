#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include "../../../Squirrel-Engine/include/Configuration.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()

class CameraComponent : public ActorComponent
{
public:
	CameraComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	const mat4& getProjection() const { return m_Projection; }
	const mat4& getViewMatrix() const { return m_ViewMatrix; }
	mat4 getViewProjection() const { return m_Projection * m_ViewMatrix; }

	void updateLookAt(const vec3& eye, const vec3& target, const vec3& up);
	void updatePerspective(float fovx, float aspect, float znear, float zfar);
	void setViewportSize(float width, float height);
private:
	void updateView();
	quat getOrientation();
private:
	static const float DEFAULT_FOVX;
	static const float DEFAULT_ZNEAR;
	static const float DEFAULT_ZFAR;

	static const vec3 WORLD_XAXIS;
	static const vec3 WORLD_YAXIS;
	static const vec3 WORLD_ZAXIS;

	//Projection Matrix Variables
	float m_FOV, m_AspectRatio, m_NearClip, m_FarClip;
	float m_ViewportWidth, m_ViewportHeight;
	mat4 m_Projection;

	//View Matrix Variables
	vec3 m_Position = vec3(0, 0, 0);
	vec3 m_Rotation = vec3(0, 0, 0);
	vec3 m_Target = vec3(0, 0, -1);
	vec3 m_Up = vec3(0, 1, 0);
	mat4 m_ViewMatrix;
};

SR_COMPONENT()
