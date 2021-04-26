#include "Material.h"

Material::Material(Texture* albedoMap, Texture* normalMap, Texture* metallicMap, Texture* roughnessMap, Texture* ambientOcclusionMap, Texture* displacementMap)
	: m_AlbedoMap(albedoMap), m_NormalMap(normalMap), m_MetallicMap(metallicMap), m_RoughnessMap(roughnessMap), m_AmbientOcclusionMap(ambientOcclusionMap), m_DisplacementMap(displacementMap),
	m_ParallaxStrength(0.07f), m_ParallaxMinSteps(PARALLAX_MIN_STEPS), m_ParallelMaxSteps(PARALLAX_MAX_STEPS)
{
}

void Material::BindMaterialInformation(Shader* shader) const {
	int currentTextureUnit = 0;

	shader->setInt("material.texture_diffuse", currentTextureUnit);
	if (m_AlbedoMap) {
		m_AlbedoMap->bind(currentTextureUnit++);
	}else {
		TextureLoader::getDefaultAlbedo()->bind(currentTextureUnit++);
	}
}
