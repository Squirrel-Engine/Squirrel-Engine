#include "RM_Interface.h"



namespace Squirrel
{
	RM_Interface::RM_Interface()
	{
	}

	void RM_Interface::loadAssetMap()
	{
		//Mesh
		meshAssetMap.insert({ 0, "../../Squirrel-Engine/res/models/sword.obj" });
		//Texture
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/sword_diff.png" });
	}

	void RM_Interface::loadAssets()
	{
		loadAssetMap();

		
		Mesh* mesh = new Mesh(meshAssetMap[0]);
		meshBuffer.insert({ 0, mesh });

		Texture* texture = new Texture(textureAssetMap[0]);
		textureBuffer.insert({ 0, texture });
		
	}

	Texture* RM_Interface::getTexture(int index)
	{
		return textureBuffer[index];
	}

	Mesh* RM_Interface::getMesh(int index)
	{
		return meshBuffer[index];
	}
}
