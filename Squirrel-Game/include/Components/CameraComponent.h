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

	const vec3& getPosition() const { return *m_Position; }
	vec3 getUpDirection() const;
	vec3 getRightDirection() const;
	vec3 getForwardDirection() const;
	quat getOrientation() const;

	const mat4& GetProjection() const { return m_Projection; }
	const mat4& getViewMatrix() const { return m_ViewMatrix; }
	mat4 getViewProjection() const { return m_Projection * m_ViewMatrix; }

	void setViewportSize(float width, float height);

	float getPitch() const { return m_Pitch; }
	float getYaw() const { return m_Yaw; }

private:
	void updateProjection();
	void updateView();

protected:
	mat4 m_Projection = mat4(1.0f);
private:
	float m_FOV = 60.0f, m_AspectRatio, m_NearClip = 0.1f, m_FarClip = 1000.0f;

	mat4 m_ViewMatrix;
	vec3* m_Position;
	vec3 m_FocalPoint = {0.0f, 0.0f, 0.0f};

	float m_Pitch = 0.0f, m_Yaw = 0.0f;

	float m_ViewportWidth, m_ViewportHeight;
};

SR_COMPONENT()
