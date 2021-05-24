#pragma once
#include "Shader.h"
#include "PointLight.h"

class DynamicLightManager
{
public:
	DynamicLightManager();

	static void bindLightingUniforms(Shader* shader);

	static void addPointLight(PointLight* pointLight);
private:
	static std::vector<PointLight*> m_PointLights;
};
