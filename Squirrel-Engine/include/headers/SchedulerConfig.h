#pragma once
#include "EScheduler.h"
#include "IConfig.h"
#include "JSONParser.h"


class SchedulerConfig : IConfig
{
public:
	EScheduler scheduler;
	bool renderDebug;
	bool mtMode;

	void setup() override;
private:
	JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/schedulerConfig.json");
};
