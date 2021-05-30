#pragma once
#include "LightObject.h"

class LightComponent;

class SpotLight : public LightObject {
	friend LightComponent;
public:
	SpotLight(float lightIntensity, glm::vec3& lightColour, float attenuationRadius, glm::vec3& pos, glm::vec3& dir, float cutOffAngle, float outerCutOffAngle);
	SpotLight(glm::vec3& pos, glm::vec3& dir);

	virtual void setupUniforms(Shader *shader, int currentLightIndex) override;
private:
	float m_AttenuationRadius;
	glm::vec3 m_Position, m_Direction;
	float m_CutOff, m_OuterCutOff;
};


