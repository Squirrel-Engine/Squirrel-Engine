#include"../../include/RenderConfig.h"
namespace Squirrel {
	void RenderConfig::setup() {
		nlohmann::json conMap = jsonConfigurator->parseConfigurations();
		if (conMap["GraphicAPI"] == "OpenGL") {
			graphicAPI = EGraphicAPI::OPENGL;
		}
	}
}