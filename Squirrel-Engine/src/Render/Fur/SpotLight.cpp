#include "SpotLight.h"

SpotLight::SpotLight(float lightIntensity, glm::vec3& lightColour, float attenuationRadius, glm::vec3& pos, glm::vec3& dir, float cutOffAngle, float outerCutOffAngle)
	: LightObject(lightIntensity, lightColour), m_AttenuationRadius(attenuationRadius), m_Position(pos), m_Direction(dir), m_CutOff(cutOffAngle), m_OuterCutOff(outerCutOffAngle) {}
SpotLight::SpotLight(glm::vec3& pos, glm::vec3& dir)
	: LightObject(1.0f, glm::vec3(255.0, 255.0, 255.0)), m_AttenuationRadius(50.0f), m_Position(pos), m_Direction(dir), m_CutOff(glm::cos(glm::radians(12.5f))), m_OuterCutOff(glm::cos(glm::radians(15.0f))) {}

void SpotLight::setupUniforms(Shader *shader, int currentLightIndex) {
	shader->setVec3(("spotLights[" + std::to_string(currentLightIndex) + "].position").c_str(), m_Position);
	shader->setVec3(("spotLights[" + std::to_string(currentLightIndex) + "].direction").c_str(), m_Direction);
	shader->setFloat(("spotLights[" + std::to_string(currentLightIndex) + "].intensity").c_str(), m_Intensity);
	shader->setVec3(("spotLights[" + std::to_string(currentLightIndex) + "].lightColour").c_str(), m_LightColour);
	shader->setFloat(("spotLights[" + std::to_string(currentLightIndex) + "].attenuationRadius").c_str(), m_AttenuationRadius);
	shader->setFloat(("spotLights[" + std::to_string(currentLightIndex) + "].cutOff").c_str(), m_CutOff);
	shader->setFloat(("spotLights[" + std::to_string(currentLightIndex) + "].outerCutOff").c_str(), m_OuterCutOff);
}