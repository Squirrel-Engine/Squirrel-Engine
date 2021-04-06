#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include "../../../Squirrel-Engine/include/ActorComponent.h"
#include "TransformComponent.h"

SR_COMPONENT()
class CameraComponent : public Squirrel::ActorComponent {
public:
	CameraComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	inline float getDistance() const { return m_Distance; }
	inline void setDistance(float distance) { m_Distance = distance; }
	const glm::mat4& GetProjection() const { return m_Projection; }

	inline void setViewportSize(float width, float height) { m_ViewportWidth = width; m_ViewportHeight = height; updateProjection(); }

	const glm::mat4& getViewMatrix() const { return m_ViewMatrix; }
	glm::mat4 getViewProjection() const { return m_Projection * m_ViewMatrix; }

	glm::vec3 getUpDirection() const;
	glm::vec3 getRightDirection() const;
	glm::vec3 getForwardDirection() const;
	const glm::vec3& getPosition() const { return m_Position; }
	glm::quat getOrientation() const;

	float getPitch() const { return m_Pitch; }
	float getYaw() const { return m_Yaw; }

private:
	void updateProjection();
	void updateView();

	glm::vec3 calculatePosition() const;
protected:
	glm::mat4 m_Projection = glm::mat4(1.0f);
private:
	float m_FOV = 60.0f, m_AspectRatio = m_ViewportWidth / m_ViewportHeight, m_NearClip = 0.1f, m_FarClip = 1000.0f;

	glm::mat4 m_ViewMatrix;
	glm::vec3 m_Position	= { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_FocalPoint	= { 0.0f, 0.0f, 0.0f };

	glm::vec2 m_InitialMousePosition = { 0.0f, 0.0f };

	float m_Distance = 3;
	float m_Pitch = 0.0f, m_Yaw = 0.0f;

	float m_ViewportWidth = 1280, m_ViewportHeight = 720;
};
SR_COMPONENT()