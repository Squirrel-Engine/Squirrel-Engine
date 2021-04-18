#include "RM_Interface.h"
#define MATERIAL_COUNT 6


int MaterialDataBase[MATERIAL_COUNT][3] = {
	//diffuse	//normal	//specular
	{0, 0, 0},
	{2, 2, 2},
	{3, 3, 3},
};

void RM_Interface::loadAssetMap()
{
	//Mesh
	meshAssetMap.insert({0, "../../Squirrel-Engine/res/models/Model.obj" });
	meshAssetMap.insert({1, "../../Squirrel-Engine/res/models/Venus.obj" });
	meshAssetMap.insert({2, "../../Squirrel-Engine/res/models/Statue.fbx" });
	
	//Texture
	textureAssetMap.insert({0, "../../Squirrel-Engine/res/textures/wall.jpg"});
	textureAssetMap.insert({1, "../../Squirrel-Engine/res/textures/test_emis.jpg"});
	textureAssetMap.insert({2, "../../Squirrel-Engine/res/textures/sci-fi_diff.jpg"});
	textureAssetMap.insert({3, "../../Squirrel-Engine/res/textures/statue.jpg" });

	//Audio
	audioAssetMap.insert({0, "../../Squirrel-Engine/res/audio/EasyStreet.wav" });
	audioAssetMap.insert({1, "../../Squirrel-Engine/res/audio/spell.ogg" });
	audioAssetMap.insert({2, "../../Squirrel-Engine/res/audio/iamtheprotectorofthissystem.wav" });
	audioAssetMap.insert({3, "../../Squirrel-Engine/res/audio/Forest.wav" });

	//Shader
	shaderAssetMap.insert({0, "../../Squirrel-Engine/res/shaders/Model.shader"});
	shaderAssetMap.insert({1, "../../Squirrel-Engine/res/shaders/LightSource.shader"});


	// TEXTURE LOADING FUNCTION !!!!!!!!!!!!
}

void RM_Interface::loadMeshAsset()
{
	for (int i = 0; i < meshAssetMap.size(); i++)
	{
		auto model = new Model(meshAssetMap[i]);
		meshBuffer.insert({i, model});
	}
}


void RM_Interface::loadAudioAsset()
{
	for (int i = 0; i < audioAssetMap.size(); i++)
	{
		Audio* audioObj = new Audio(audioAssetMap[i]);
		audioBuffer.insert({ i, audioObj });
	}

}


void RM_Interface::loadTextureAsset()
{
	for (int i = 0; i < textureAssetMap.size(); i++)
	{
		auto texture = new Texture(textureAssetMap[i]);
		textureBuffer.insert({i, texture});
	}
}

void RM_Interface::loadShaderAsset()
{
	for (int i = 0; i < shaderAssetMap.size(); i++)
	{
		auto shader = new Shader(shaderAssetMap[i]);
		shaderBuffer.insert({i, shader});
	}
}

void RM_Interface::loadMaterialAsset()
{
	for (int i = 0; i < MATERIAL_COUNT; i++)
	{
		auto material = new Material();
		material->setTexture("texture_diffuse", textureAssetMap.at(MaterialDataBase[i][0]));
		material->setTexture("texture_normal", textureAssetMap.at(MaterialDataBase[i][1]));
		material->setTexture("texture_specular", textureAssetMap.at(MaterialDataBase[i][2]));

		materialBuffer.insert({ i, material });
	}
}

void RM_Interface::loadAssetMT()
{
	loadAssetMap();
	loadMeshAsset();
	loadTextureAsset();
	loadMaterialAsset();
	loadShaderAsset();
	loadAudioAsset();
}

Model* RM_Interface::getMesh(int index)
{
	return meshBuffer[index];
}

Texture* RM_Interface::getTexture(int index)
{
	return textureBuffer[index];
}


Audio* RM_Interface::getAudio(int index)
{
  return audioBuffer[index];
}

Shader* RM_Interface::getShader(int index)
{
	return shaderBuffer[index];
}

Material* RM_Interface::getMaterial(int index)
{
	return materialBuffer[index];
}
