#pragma once
#include "LightObject.h"

class LightComponent;
class DirectionalLight : public LightObject {
	friend LightComponent;
public:
	DirectionalLight(float lightIntensity, glm::vec3 &lightColour, glm::vec3 &dir);
	DirectionalLight();

	virtual void setupUniforms(Shader *shader, int currentLightIndex) override;
public:
	glm::vec3 m_Direction;
};


