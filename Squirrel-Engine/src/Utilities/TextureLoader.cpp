#include "TextureLoader.h"
#include "pch.h"

// Static declarations
std::unordered_map<std::string, Texture*> TextureLoader::m_TextureCache;
Texture* TextureLoader::s_DefaultAlbedo;
Texture* TextureLoader::s_DefaultNormal;
Texture* TextureLoader::s_WhiteTexture; 
Texture* TextureLoader::s_BlackTexture;

Texture* TextureLoader::load2DTexture(std::string& path, TextureSettings* settings) {
	// Check the cache
	auto iter = m_TextureCache.find(path);
	if (iter != m_TextureCache.end()) {
		return iter->second;
	}

	// Load the texture
	int width, height, numComponents;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &numComponents, 0);
	if (!data) {
		stbi_image_free(data);
		return nullptr;
	}

	GLenum dataFormat;
	switch (numComponents) {
	case 1: dataFormat = GL_RED;  break;
	case 3: dataFormat = GL_RGB;  break;
	case 4: dataFormat = GL_RGBA; break;
	}

	Texture* texture = nullptr;
	if (settings != nullptr) {
		texture = new Texture(*settings);
	}
	else {
		texture = new Texture();
	}

	texture->generate2DTexture(width, height, dataFormat, GL_UNSIGNED_BYTE, data);

	m_TextureCache.insert(std::pair<std::string, Texture*>(path, texture));
	stbi_image_free(data);

	return m_TextureCache[path];
}


void TextureLoader::initializeDefaultTextures() {
	TextureSettings srgbTextureSettings;
	srgbTextureSettings.IsSRGB = true;

	s_DefaultAlbedo = load2DTexture(std::string("../../Squirrel-Engine/res/textures/default/defaultAlbedo.png"), &srgbTextureSettings);
	s_DefaultAlbedo->bind();
	s_DefaultAlbedo->setTextureMinFilter(GL_NEAREST);
	s_DefaultAlbedo->setTextureMagFilter(GL_NEAREST);
	s_DefaultNormal = load2DTexture(std::string("../../Squirrel-Engine/res/textures/default/defaultNormal.png"));
	s_DefaultNormal->bind();
	s_DefaultNormal->setTextureMinFilter(GL_NEAREST);
	s_DefaultNormal->setTextureMagFilter(GL_NEAREST);
	s_WhiteTexture = load2DTexture(std::string("../../Squirrel-Engine/res/textures/default/white.png"));
	s_WhiteTexture->bind();
	s_WhiteTexture->setTextureMinFilter(GL_NEAREST);
	s_WhiteTexture->setTextureMagFilter(GL_NEAREST);
	s_BlackTexture = load2DTexture(std::string("../../Squirrel-Engine/res/textures/default/black.png"));
	s_BlackTexture->bind();
	s_BlackTexture->setTextureMinFilter(GL_NEAREST);
	s_BlackTexture->setTextureMagFilter(GL_NEAREST);
}