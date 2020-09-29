#pragma once
#include"IConfig.h"
#include"EGraphicAPI.h"
#include"JSONConfigurator.h"
#include "../../../include/json.hpp"
namespace Squirrel {
	class RenderConfig :IConfig {
	public:
		EGraphicAPI graphicAPI;
		JSONConfigurator* jsonConfigurator = new JSONConfigurator("C:/Users/16070001006/Projects/Squirrel-Engine/Squirrel-Engine/src/configs/renderConfig.json");
		void setup();
	};
}

