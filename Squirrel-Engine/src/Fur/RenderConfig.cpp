#include"include/RenderConfig.h"
namespace Fur {

	RenderConfig::RenderConfig()
	{
		setup();
	}

	void RenderConfig::setup() {
		nlohmann::json conMap = jsonConfigurator->parseFile_json();
		if (conMap["Renderer"] == "Fur") {
			renderer = Squirrel::ERenderer::Fur;
		}
		screenWidth = conMap["screenWidth"];
		screenHeight = conMap["screenHeight"];
		windowName = conMap["windowName"];
	}
}