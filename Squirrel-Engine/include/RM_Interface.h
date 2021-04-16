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
		RM_Interface(){}
		~RM_Interface() {}
		//void loadAssetMap(FILE* fp);
		void loadAssetMap();

		void loadMeshAsset();
		void loadTextureAsset();
		void loadMaterialAsset();
		void loadShaderAsset();
		void loadAssetMT();

		Model* getMesh(int index);
		Texture* getTexture(int index);
		Shader* getShader(int index);
		Material* getMaterial(int index);
		//Model

		//Tex
		std::unordered_map<int, const std::string> meshAssetMap;
		std::unordered_map<int, std::string> textureAssetMap;
		std::unordered_map<int, std::string> shaderAssetMap;
		//Thread
		std::mutex meshesMutex;
		std::vector<std::thread> vecOfThreads;

		std::unordered_map<int, Model*> meshBuffer;
		std::unordered_map<int, Texture*> textureBuffer;
		std::unordered_map<int, Material*> materialBuffer;
		std::unordered_map<int, Shader*> shaderBuffer;
		
		int assignAsset();
	private:

	};
}
