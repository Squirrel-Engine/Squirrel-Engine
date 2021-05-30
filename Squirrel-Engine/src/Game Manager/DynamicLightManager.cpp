#include "DynamicLightManager.h"

std::vector<PointLight*> DynamicLightManager::m_PointLights;
std::vector<DirectionalLight*> DynamicLightManager::m_DirectionalLights;
std::vector<SpotLight*> DynamicLightManager::m_SpotLights;


DynamicLightManager::DynamicLightManager()
{
	
}

void DynamicLightManager::bindLightingUniforms(Shader* shader) {
	shader->setIVec4("numLights", glm::ivec4(m_DirectionalLights.size(), m_PointLights.size(), m_SpotLights.size(), 0));
	int i = 0;
	for (auto& iter = m_DirectionalLights.begin(); iter != m_DirectionalLights.end(); iter++) {
		(*iter)->setupUniforms(shader, i++);
	}

	i = 0;
	for (auto& iter = m_PointLights.begin(); iter != m_PointLights.end(); iter++) {
		(*iter)->setupUniforms(shader, i++);
	}

	i = 0;
	for (auto& iter = m_SpotLights.begin(); iter != m_SpotLights.end(); iter++) {
		(*iter)->setupUniforms(shader, i++);
	}
}

void DynamicLightManager::addDirectionalLight(DirectionalLight* dirLight) {
	m_DirectionalLights.push_back(dirLight);
}

void DynamicLightManager::addPointLight(PointLight* pointLight) {
	m_PointLights.push_back(pointLight);
}

void DynamicLightManager::addSpotLight(SpotLight* spotLight)
{
	m_SpotLights.push_back(spotLight);
}
