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
		meshAssetMap.insert({ 1, "../../Squirrel-Engine/res/models/sword.obj" });
		meshAssetMap.insert({ 2, "../../Squirrel-Engine/res/models/Model2.obj" });
		meshAssetMap.insert({ 3, "../../Squirrel-Engine/res/models/Model2.obj" });

		//Texture
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/wall.jpg" });
		// TEXTURE LOADING FUNCTION !!!!!!!!!!!!

	}

	void RM_Interface::loadMeshAsset(int i)
	{
		
	}

	void RM_Interface::loadTextureAsset(int i)
	{
		Texture* texture = new Texture(textureAssetMap[0]);
		textureBuffer.insert({ 0, texture });
	} 

	void RM_Interface::loadAssetMT()
	{
		loadAssetMap();
		loadMeshAsset(0);
		loadTextureAsset(0);
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
}
