#include <dinput.h>
#include <map>
#include <string>
#include <thread>
#include <vector>
#include "Mesh.h"
#include <mutex>
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
		std::mutex mt;
		Mesh* getMesh(int index);
		Texture* getTexture(int index);
		//Model

		//Tex
		//Tex
		std::map<int, const std::string> meshAssetMap;
		std::map<int, std::string> textureAssetMap;


		std::map<int, Mesh*> meshBuffer;
		std::map<int, Texture*> textureBuffer;

		int assignAsset();
		void threadProcess(std::map<int, Mesh*>* buffer);
	};
}
