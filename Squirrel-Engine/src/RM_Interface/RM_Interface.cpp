#include "RM_Interface.h"
#define MATERIAL_COUNT 4


int MaterialDataBase[MATERIAL_COUNT][3] = {
	//diffuse	//normal	//specular
	{0, 1, 2},
	{0, 1, 2},
	{0, 1, 2}
};

void RM_Interface::loadAssetMap()
{
	//Mesh
	meshAssetMap.insert({0, "../../Squirrel-Engine/res/models/Model1.obj"});
	meshAssetMap.insert({1, "../../Squirrel-Engine/res/models/girl2.fbx"});
	meshAssetMap.insert({2, "../../Squirrel-Engine/res/models/backpack/backpack.obj"});

	//Texture
	textureAssetMap.insert({0, "../../Squirrel-Engine/res/textures/wall.jpg"});
	textureAssetMap.insert({1, "../../Squirrel-Engine/res/textures/test_emis.jpg"});
	textureAssetMap.insert({2, "../../Squirrel-Engine/res/textures/sci-fi_diff.jpg"});


		audioAssetMap.insert({0, "../../Squirrel-Engine/res/audio/EasyStreet.wav"});
		audioAssetMap.insert({ 1, "../../Squirrel-Engine/res/audio/spell.ogg" });
		audioAssetMap.insert({ 2, "../../Squirrel-Engine/res/audio/iamtheprotectorofthissystem.wav"});
		audioAssetMap.insert({ 3, "../../Squirrel-Engine/res/audio/Pala.wav" });
		// TEXTURE LOADING FUNCTION !!!!!!!!!!!!
	}

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

void RM_Interface::loadShaderAsset()
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

		loadAssetMap();
		loadMeshAsset();
		loadTextureAsset();
		loadMaterialAsset();
		loadAudioAsset();
		loadShaderAsset();
	}
=======
		auto material = new Material();
		material->setTexture("texture_diffuse", textureAssetMap.at(MaterialDataBase[i][0]));
		material->setTexture("texture_normal", textureAssetMap.at(MaterialDataBase[i][1]));
		material->setTexture("texture_specular", textureAssetMap.at(MaterialDataBase[i][2]));


		materialBuffer.insert({i, material});
	}
}

void RM_Interface::loadAssetMT()
{
	loadAssetMap();
	loadMeshAsset();
	loadTextureAsset();
	loadMaterialAsset();
	loadShaderAsset();
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
