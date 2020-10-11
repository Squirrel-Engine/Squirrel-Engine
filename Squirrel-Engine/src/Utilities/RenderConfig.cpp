#include"include/RenderConfig.h"
namespace Squirrel {
	void RenderConfig::setup() {
		nlohmann::json conMap = jsonConfigurator->parseFile_json();
		if (conMap["GraphicAPI"] == "OpenGL") {
			graphicAPI = EGraphicAPI::OPENGL;
		}
		screenWidth = conMap["screenWidth"];
		screenHeight = conMap["screenHeight"];
		windowName = conMap["windowName"];
	}
}