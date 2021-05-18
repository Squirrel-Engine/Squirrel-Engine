#include "Material.h"

Material::Material(Texture* albedoMap, Texture* normalMap, Texture* metallicMap, Texture* roughnessMap, Texture* ambientOcclusionMap, Texture* displacementMap)
	: m_AlbedoMap(albedoMap), m_NormalMap(normalMap), m_MetallicMap(metallicMap), m_RoughnessMap(roughnessMap), m_AmbientOcclusionMap(ambientOcclusionMap), m_DisplacementMap(displacementMap),
	m_ParallaxStrength(0.07f), m_ParallaxMinSteps(PARALLAX_MIN_STEPS), m_ParallelMaxSteps(PARALLAX_MAX_STEPS)
{
}

void Material::setupUniforms(Shader* shader) const {
	int currentTextureUnit = 0;

	shader->setInt("material.albedo", currentTextureUnit);
	if (m_AlbedoMap) {
		m_AlbedoMap->bind(currentTextureUnit++);
	}
	else {
		TextureLoader::getDefaultAlbedo()->bind(currentTextureUnit++);
	}
	
	shader->setInt("material.normal", currentTextureUnit);
	if (m_NormalMap) {
		m_NormalMap->bind(currentTextureUnit++);
	}
	else {
		TextureLoader::getDefaultNormal()->bind(currentTextureUnit++);
	}

	shader->setInt("material.metallic", currentTextureUnit);
	if (m_MetallicMap) {
		m_MetallicMap->bind(currentTextureUnit++);
	}
	else {
		TextureLoader::getDefaultMetallic()->bind(currentTextureUnit++);
	}

	shader->setInt("material.roughness", currentTextureUnit);
	if (m_RoughnessMap) {
		m_RoughnessMap->bind(currentTextureUnit++);
	}
	else {
		TextureLoader::getDefaultRoughness()->bind(currentTextureUnit++);
	}

	shader->setInt("material.ao", currentTextureUnit);
	if (m_AmbientOcclusionMap) {
		m_AmbientOcclusionMap->bind(currentTextureUnit++);
	}
	else {
		TextureLoader::getDefaultAO()->bind(currentTextureUnit++);
	}
}
