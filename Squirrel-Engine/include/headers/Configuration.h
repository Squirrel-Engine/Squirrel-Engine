#pragma once
#include "AudioConfig.h"
#include "RenderConfig.h"
#include "SchedulerConfig.h"
	
class Configuration
{
private:
	Configuration();

public:
	static Configuration& getInstance();
	RenderConfig renderConfig;
	SchedulerConfig schedulerConfig;
	AudioConfig audioConfig;
};