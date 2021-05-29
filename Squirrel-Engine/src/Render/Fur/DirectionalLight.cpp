#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(float lightIntensity, glm::vec3 &lightColour, glm::vec3 &dir)
	: LightObject(lightIntensity, lightColour), m_Direction(dir) {}
DirectionalLight::DirectionalLight()
	: LightObject(2.0f, glm::vec3(3.25f, 3.25f, 3.25f)), m_Direction(glm::vec3(0.0f, -1.0f, -0.2f)) {}

void DirectionalLight::setupUniforms(Shader *shader, int currentLightIndex) {
	shader->setVec3(("dirLights[" + std::to_string(currentLightIndex) + "].direction").c_str(), m_Direction);
	shader->setFloat(("dirLights[" + std::to_string(currentLightIndex) + "].intensity").c_str(), m_Intensity);
	shader->setVec3(("dirLights[" + std::to_string(currentLightIndex) + "].lightColour").c_str(), m_LightColour);
}