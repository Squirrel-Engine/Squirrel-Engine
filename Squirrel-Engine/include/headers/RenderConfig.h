#pragma once
#include"IConfig.h"
#include"JSONParser.h"
#include "ERenderer.h"
#include "json.hpp"

class RenderConfig : IConfig
{
public:
	RenderConfig();

	ERenderer renderer;
	int screenWidth;
	int screenHeight;
	std::string windowName;

	void setup() override;
private:
	JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/renderConfig.json");
};
