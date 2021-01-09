
#include <map>
#include <string>

namespace Squirrel
{
	class AssetDatabase
	{
		std::map<int, std::string&> vsShaderDB;
		std::map<int, std::string&> fsShaderDB;
		std::map<int, std::string&> textureDB;
		std::map<int, std::string&> meshDB;
		void loadDB();
		
	};
}

