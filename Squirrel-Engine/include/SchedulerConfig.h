#pragma once
#include "EScheduler.h"
#include "IConfig.h"
#include "JSONParser.h"

namespace Squirrel
{
	class SchedulerConfig : Squirrel::IConfig
	{
	public:
		EScheduler scheduler;
		bool renderDebug;
		
		void setup();
	private:
		JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/schedulerConfig.json");
		
	};


}
