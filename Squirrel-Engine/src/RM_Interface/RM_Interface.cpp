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

		


		
		// TEXTURE LOADING FUNCTION !!!!!!!!!!!!
	}

	void RM_Interface::loadMeshAsset(int i)
	{
		Model* model = new Model(meshAssetMap[0]);
		meshBuffer.insert({ 0, model });
	}

	void RM_Interface::loadTextureAsset(int i)
	{
		Texture* texture = new Texture(textureAssetMap[0]);
		textureBuffer.insert({ 0, texture });
	}

	void RM_Interface::loadMaterialAsset( )
	{
		Material* material = new Material();
		material->setTexture("texture_diffuse", textureAssetMap.at(0));
		materialBuffer.insert({ 0, material});
		getMesh(0).meshes.at(0).material = *material;
	}



	void RM_Interface::loadAssetMT()
	{
		loadAssetMap();
		loadMeshAsset(0);
		loadTextureAsset(0);
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

	void RM_Interface::loadShaderAsset()
	{
		Shader* shader = new Shader(shaderAssetMap[0]);
		shaderBuffer.insert({ 0, shader });
	}
}
