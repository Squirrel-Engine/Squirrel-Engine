#pragma once
#include "Shader.h"
#include "UniformDesc.h"

enum class ELightType {
	DirectionalLight,
	PointLight,
	SpotLight
};

class LightObject
{
private:

public:
	LightObject(float lightIntensity, glm::vec3& lightColour);
	LightObject();
	~LightObject();
	virtual void setupUniforms(Shader* shader, int currentLightIndex) = 0;
protected:
	float m_Intensity;
	glm::vec3 m_LightColour;
};
