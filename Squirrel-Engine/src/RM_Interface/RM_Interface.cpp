#include "RM_Interface.h"

namespace Squirrel
{
	void RM_Interface::loadAssetMap()
	{
		//Mesh
		meshAssetMap.insert({ 0, "../../Squirrel-Engine/res/models/Model1.obj" });
		

		//Texture
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/wall.jpg" });

		//Shader
		shaderAssetMap.insert({ 0, "../../Squirrel-Engine/res/shaders/Model.shader" });

		//Material
		materialCount = 1;


		
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
			material->setTexture("texture_diffuse", textureAssetMap.at(0));
			material->setTexture("texture_normal", textureAssetMap.at(0));
			material->setTexture("texture_specular", textureAssetMap.at(0));
			getMesh(0).meshes.at(0).material = *material;
			materialBuffer.insert({ 0, material });
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

	int RM_Interface::assignAsset()
	{
		return 0;
	}

	Model& RM_Interface::getMesh(int index)
	{
		return *meshBuffer[index];
	}

	Texture& RM_Interface::getTexture(int index)
	{
		return *textureBuffer[index];
	}

	Shader& RM_Interface::getShader(int index)
	{
		return *shaderBuffer[index];
	}


}
