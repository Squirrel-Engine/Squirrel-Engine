#include"include/RenderConfig.h"
namespace Squirrel {
	void RenderConfig::setup() {
		nlohmann::json conMap = jsonConfigurator->parseFile_json();
		if (conMap["Renderer"] == "Fur") {
			renderer = ERenderer::Fur;
		}
		screenWidth = conMap["screenWidth"];
		screenHeight = conMap["screenHeight"];
		windowName = conMap["windowName"];
		 
	}
}