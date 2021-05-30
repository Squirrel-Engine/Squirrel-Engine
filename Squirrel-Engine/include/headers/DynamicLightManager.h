#pragma once
#include "Shader.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class DynamicLightManager
{
public:
	DynamicLightManager();

	static void bindLightingUniforms(Shader* shader);

	static void addDirectionalLight(DirectionalLight* dirLight);
	static void addPointLight(PointLight* pointLight);
	static void addSpotLight(SpotLight* pointLight);
private:
	static std::vector<DirectionalLight*> m_DirectionalLights;
	static std::vector<PointLight*> m_PointLights;
	static std::vector<SpotLight*> m_SpotLights;
};
