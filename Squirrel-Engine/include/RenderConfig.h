#pragma once
#include"IConfig.h"
#include"EGraphicAPI.h"
#include"JSONParser.h"
#include "../../../include/json.hpp"
namespace Squirrel {
	class RenderConfig :IConfig {
	public:
		EGraphicAPI graphicAPI;
		JSONParser* jsonConfigurator = new JSONParser("C:/Users/16070001006/Projects/Squirrel-Engine/Squirrel-Engine/src/configs/renderConfig.json");
		void setup();
	};
}

