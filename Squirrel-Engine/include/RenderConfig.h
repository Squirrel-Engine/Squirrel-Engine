#pragma once
#include"IConfig.h"
#include"JSONParser.h"
#include "vendor/json.hpp"
#include "ERenderer.h"

class RenderConfig : IConfig {
public:
	RenderConfig();

	ERenderer renderer;
	int screenWidth;
	int screenHeight;
	std::string windowName;

	void setup();
private:
	JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/renderConfig.json");
};