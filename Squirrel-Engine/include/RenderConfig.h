#pragma once
#include"IConfig.h"
#include"EGraphicAPI.h"
#include"JSONParser.h"
#include "vendor/json.hpp"
#include "ERenderer.h"

namespace Fur {
	class RenderConfig : Squirrel::IConfig {
	public:
		RenderConfig();

		Squirrel::ERenderer renderer;
		int screenWidth;
		int screenHeight;
		std::string windowName;

		void setup();
	private:
		Squirrel::JSONParser* jsonConfigurator = new Squirrel::JSONParser("../../Squirrel-Engine/src/configs/renderConfig.json");
	};
}

