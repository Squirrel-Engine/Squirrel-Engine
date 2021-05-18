#include "PointLight.h"

PointLight::PointLight(float lightIntensity, glm::vec3& lightColour, float attenuationRadius, glm::vec3& pos)
	: LightObject(lightIntensity, lightColour), m_AttenuationRadius(attenuationRadius), m_Position(pos) {}
PointLight::PointLight(glm::vec3& pos)
	: LightObject(), m_Position(pos) {}

PointLight::~PointLight	()
{

}

void PointLight::setupUniforms(Shader* shader, int currentLightIndex) {
	shader->setVec3(("pointLights[" + std::to_string(currentLightIndex) + "].position").c_str(), m_Position);
	shader->setFloat(("pointLights[" + std::to_string(currentLightIndex) + "].intensity").c_str(), m_Intensity);
	shader->setVec3(("pointLights[" + std::to_string(currentLightIndex) + "].lightColour").c_str(), m_LightColour);
	shader->setFloat(("pointLights[" + std::to_string(currentLightIndex) + "].attenuationRadius").c_str(), m_AttenuationRadius);
}