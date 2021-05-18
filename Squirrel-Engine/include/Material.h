#pragma once
#include <iostream>
#include "Shader.h"
#include "Texture.h"
#include "TextureLoader.h"

#define PARALLAX_MIN_STEPS 1
#define PARALLAX_MAX_STEPS 20
using namespace std;
class Material {
public:
	Material(Texture* albedoMap = nullptr, Texture* normalMap = nullptr, Texture* metallicMap = nullptr, Texture* roughnessMap = nullptr, Texture* ambientOcclusionMap = nullptr, Texture* displacementMap = nullptr);

	void setupUniforms(Shader* shader) const;

	inline void setAlbedoMap(Texture* texture) { m_AlbedoMap = texture; }
	inline void setNormalMap(Texture* texture) { m_NormalMap = texture; }
	inline void setMetallicMap(Texture* texture) { m_MetallicMap = texture; }
	inline void setRoughnessMap(Texture* texture) { m_RoughnessMap = texture; }
	inline void setAmbientOcclusionMap(Texture* texture) { m_AmbientOcclusionMap = texture; }
	inline void setDisplacementMap(Texture* texture) { m_DisplacementMap = texture; }

	inline void setDisplacmentStrength(float strength) { m_ParallaxStrength = strength; }
private:
	Texture* m_AlbedoMap, * m_NormalMap, * m_MetallicMap, * m_RoughnessMap, * m_AmbientOcclusionMap, * m_DisplacementMap;
	float m_ParallaxStrength;
	int m_ParallaxMinSteps, m_ParallelMaxSteps; 
};