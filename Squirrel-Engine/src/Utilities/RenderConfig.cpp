#include"../../include/RenderConfig.h"
namespace Squirrel {
	void RenderConfig::setup() {
		nlohmann::json conMap = jsonConfigurator->parseFiles();
		if (conMap["GraphicAPI"] == "OpenGL") {
			graphicAPI = EGraphicAPI::OPENGL;
		}
	}
}