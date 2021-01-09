
namespace Squirrel
{
	class Material
	{
	public:
		int vsShaderID;
		int fsShaderID;
		int textureID; // This should be vector for add multiple texture in one shot

		Material(int vsShaderID, int fsShaderID, int textureID);
	};
}

