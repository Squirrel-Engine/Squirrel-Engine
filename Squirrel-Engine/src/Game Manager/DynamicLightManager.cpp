#include "DynamicLightManager.h"

DynamicLightManager::DynamicLightManager()
{
	
}

void DynamicLightManager::bindLightingUniforms(Shader* shader) {
	int i = 0;
	
	for (auto& iter = m_PointLights.begin(); iter != m_PointLights.end(); iter++) {
		(*iter)->setupUniforms(shader, i++);
	}
}

void DynamicLightManager::addPointLight(PointLight* pointLight) {
	m_PointLights.push_back(pointLight);
}