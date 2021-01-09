#include "include/Material.h"

namespace Squirrel
{
	Material::Material(int _vsShaderID, int _fsShaderID, int _textureID)
	{
		vsShaderID = _vsShaderID;
		fsShaderID = _fsShaderID;
		textureID = _textureID;
	}
}

