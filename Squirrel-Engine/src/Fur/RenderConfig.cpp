#include"RenderConfig.h"

RenderConfig::RenderConfig()
{
	setup();
}

void RenderConfig::setup()
{
	nlohmann::json conMap = jsonConfigurator->parseFile_json();
	if (conMap["Renderer"] == "Fur")
	{
		renderer = ERenderer::Fur;
	}
	screenWidth = conMap["screenWidth"];
	screenHeight = conMap["screenHeight"];
	windowName = conMap["windowName"];
}
