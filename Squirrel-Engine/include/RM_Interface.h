#include <map>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

#include "Model.h"
#include "Texture.h"
#include "Timer.h" 
namespace Squirrel
{
	class RM_Interface
	{
	public:
		RM_Interface();
		//void loadAssetMap(FILE* fp);
		void loadAssetMap();

		void loadMeshAsset(int i);
		void loadTextureAsset(int i);
		void loadAssetMT();

		Model* getMesh(int index);
		Texture* getTexture(int index);
		//Model

		//Tex
		std::map<int, const std::string> meshAssetMap;
		std::map<int, std::string> textureAssetMap;
	
		//Thread
		std::mutex meshesMutex;
		std::vector<std::thread> vecOfThreads;

		std::map<int, Model*> meshBuffer;
		std::map<int, Texture*> textureBuffer;

		int assignAsset();
	};
}
