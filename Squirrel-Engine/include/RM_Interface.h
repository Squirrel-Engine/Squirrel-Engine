#include <dinput.h>
#include <map>
#include <string>
#include <vector>

#include "Mesh.h"
#include "Texture.h"

namespace Squirrel
{
	class RM_Interface
	{
	public:
		RM_Interface();
		//void loadAssetMap(FILE* fp);
		void loadAssetMap();

		void loadAssets();

		Mesh* getMesh(int index);
		Texture* getTexture(int index);
		//Model

		//Tex
		//Tex
		std::map<int, const std::string> meshAssetMap;
		std::map<int, std::string> textureAssetMap;


		std::map<int, Mesh*> meshBuffer;
		std::map<int, Texture*> textureBuffer;

	};
}
