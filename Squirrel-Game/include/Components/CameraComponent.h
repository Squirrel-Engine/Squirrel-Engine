#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include "../../../Squirrel-Engine/include/ActorComponent.h"
#include "../../../Squirrel-Engine/include/Configuration.h"
#include "TransformComponent.h"

SR_COMPONENT()
class CameraComponent : public ActorComponent {
public:
	CameraComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	const glm::vec3& getPosition() const { return *m_Position; }
	glm::vec3 getUpDirection() const;
	glm::vec3 getRightDirection() const;
	glm::vec3 getForwardDirection() const;
	glm::quat getOrientation() const;

	const glm::mat4& GetProjection() const { return m_Projection; }
	const glm::mat4& getViewMatrix() const { return m_ViewMatrix; }
	glm::mat4 getViewProjection() const { return m_Projection * m_ViewMatrix; }

	inline void setViewportSize(float width, float height) { m_ViewportWidth = width; m_ViewportHeight = height; updateProjection(); }
	inline float getPitch() const { return m_Pitch; }
	inline float getYaw() const { return m_Yaw; }

private:
	void updateProjection();
	void updateView();

protected:
	glm::mat4 m_Projection = glm::mat4(1.0f);
private:
	float m_FOV = 60.0f, m_AspectRatio, m_NearClip = 0.1f, m_FarClip = 1000.0f;

	glm::mat4 m_ViewMatrix;
	glm::vec3 *m_Position;
	glm::vec3 m_FocalPoint	= { 0.0f, 0.0f, 0.0f };

	float m_Pitch = 0.0f, m_Yaw = 0.0f;

	float m_ViewportWidth, m_ViewportHeight;
};
SR_COMPONENT()