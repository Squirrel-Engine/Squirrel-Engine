#pragma once
#include"IConfig.h"
#include"EGraphicAPI.h"
#include"JSONParser.h"
#include "json.hpp"
#include "../../build/Squirrel-Engine/ERenderer.h"

namespace Squirrel {
	class RenderConfig :IConfig {
	public:
		EGraphicAPI graphicAPI;
		JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/renderConfig.json");
		ERenderer renderer;
		int screenWidth;
		int screenHeight;
		std::string windowName;

		void setup();
	};
}

