#include "RM_Interface.h"

namespace Squirrel
{
	void RM_Interface::loadAssetMap()
	{
		//Mesh
		meshAssetMap.insert({ 0, "../../Squirrel-Engine/res/models/Model1.obj" });
		meshAssetMap.insert({ 1, "../../Squirrel-Engine/res/models/girl2.fbx" });
		meshAssetMap.insert({ 2, "../../Squirrel-Engine/res/models/backpack/backpack.obj" });
		//Texture
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/wall.jpg" });
		textureAssetMap.insert({ 1, "../../Squirrel-Engine/res/textures/test_emis.jpg" });

		//Shader
		shaderAssetMap.insert({ 0, "../../Squirrel-Engine/res/shaders/Model.shader" });

		//Material
		materialCount = 2;


		audioAssetMap.insert({0, "../../Squirrel-Engine/res/audio/EasyStreet.wav"});
		audioAssetMap.insert({ 1, "../../Squirrel-Engine/res/audio/spell.ogg" });
		audioAssetMap.insert({ 2, "../../Squirrel-Engine/res/audio/iamtheprotectorofthissystem.wav"});

		// TEXTURE LOADING FUNCTION !!!!!!!!!!!!
	}

	void RM_Interface::loadMeshAsset()
	{
		for (int i = 0; i < meshAssetMap.size(); i++)
		{
			Model* model = new Model(meshAssetMap[i]);
			meshBuffer.insert({ i, model });
		}
	}

	void RM_Interface::loadTextureAsset()
	{
		for (int i = 0; i < textureAssetMap.size(); i++)
		{
			Texture* texture = new Texture(textureAssetMap[i]);
			textureBuffer.insert({ i, texture });
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
	{
		for (int i = 0; i < shaderAssetMap.size(); i++)
		{
			Shader* shader = new Shader(shaderAssetMap[i]);
			shaderBuffer.insert({ i, shader });
		}
	}

	void RM_Interface::loadMaterialAsset( )
	{
		for (int i = 0; i < materialCount; i++)
		{
			Material* material = new Material();
			material->setTexture("texture_diffuse", textureAssetMap.at(i));
			material->setTexture("texture_normal", textureAssetMap.at(i));
			material->setTexture("texture_specular", textureAssetMap.at(i));

			materialBuffer.insert({ i, material });
		
		}
	}

	void RM_Interface::loadAssetMT()
	{
		loadAssetMap();
		loadMeshAsset();
		loadTextureAsset();
		loadMaterialAsset();
		loadAudioAsset();
		loadShaderAsset();
	}

	int RM_Interface::assignAsset()
	{
		return 0;
	}

	Model* RM_Interface::getMesh(int index)
	{
		return meshBuffer[index];
	}

	Texture* RM_Interface::getTexture(int index)
	{
		return textureBuffer[index];
	}

	Shader* RM_Interface::getShader(int index)
	{
		return shaderBuffer[index];
	}

	Material* RM_Interface::getMaterial(int index)
	{
		return materialBuffer[index];
	}

	Audio* RM_Interface::getAudio(int index)
	{
		return audioBuffer[index];
	}
}
