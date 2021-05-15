#pragma once
#include "Shader.h"
#include "PointLight.h"

class DynamicLightManager
{
public:
	DynamicLightManager();

	void bindLightingUniforms(Shader* shader);

	void addPointLight(PointLight* pointLight);
private:
	Shader* shader;
	std::vector<PointLight> m_PointLights;
};