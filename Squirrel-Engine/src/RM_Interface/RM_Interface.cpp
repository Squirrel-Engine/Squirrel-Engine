#include "RM_Interface.h"

#include <iostream>
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
		textureAssetMap.insert({ 0, "../../Squirrel-Engine/res/textures/sword_diff.png" });
		// TEXTURE LOADING FUNCTION !!!!!!!!!!!!
	}
	
	void RM_Interface::threadProcess(std::map<int, Mesh*>* buffer)
	{
		std::unique_lock<std::mutex> nlock(mt);
		std::cout << "THREAD";
		Texture* texture = new Texture(textureAssetMap[0]);
		textureBuffer.insert({ 0, texture });
		nlock.unlock();
	}
	
	void RM_Interface::loadMeshAsset(int i)
	{
		Mesh* mesh = new Mesh(meshAssetMap[i]);
		meshBuffer.insert({ i, mesh });
	}

	void RM_Interface::loadTextureAsset(int i)
	{
	} 

	void RM_Interface::loadAssetMT()
	{
		loadAssetMap();
		Mesh* mesh2 = new Mesh(RM_Interface::meshAssetMap[0]);
		meshBuffer.insert({ 0, mesh2 });
		std::vector<std::thread> vecOfThreads;
		vecOfThreads.push_back(std::thread(&RM_Interface::threadProcess, this, &meshBuffer));
		vecOfThreads.back().join();

		
	}




	int RM_Interface::assignAsset()
	{
		return 0;
	}

	Mesh* RM_Interface::getMesh(int index)
	{
		return meshBuffer[index];
	}

	Texture* RM_Interface::getTexture(int index)
	{
		return textureBuffer[index];
	}
}
