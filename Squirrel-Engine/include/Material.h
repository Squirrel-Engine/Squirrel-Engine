
#include <vector>

namespace Squirrel
{
	class Material
	{
	public:
		int shaderID;
		int textureID; // This should be vector for add multiple texture in one shot

		Material(int shaderID, int textureID);
	};
}

