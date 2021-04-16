#include "RM_Interface.h"
#define MATERIAL_COUNT 4

namespace Squirrel
{
	int MaterialDataBase[MATERIAL_COUNT][3] = {
	//diffuse	//normal	//specular
		{0,			1,			2},
		{0,			1,			2},
		{0,			1,			2}
	};

	void RM_Interface::loadAssetMap()
	{
		//Mesh
		meshAssetMap.insert({ 0, "../../Squirrel-Engine/res/models/Model1.obj" });
		meshAssetMap.insert({ 1, "../../Squirrel-Engine/res/models/girl2.fbx" });
		meshAssetMap.insert({ 2, "../../Squirrel-Engine/res/models/backpack/backpack.obj" });
		
		//Texture
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/wall.jpg" });
		textureAssetMap.insert({ 1, "../../Squirrel-Engine/res/textures/test_emis.jpg" });
		textureAssetMap.insert({ 2, "../../Squirrel-Engine/res/textures/sci-fi_diff.jpg" });

		//Shader
		shaderAssetMap.insert({ 0, "../../Squirrel-Engine/res/shaders/Model.shader" });
		shaderAssetMap.insert({ 1, "../../Squirrel-Engine/res/shaders/LightSource.shader" });

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
		for (int i = 0; i < MATERIAL_COUNT; i++)
		{
			Material* material = new Material();
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
}
