#pragma once
#include "AudioConfig.h"
#include "RenderConfig.h"
#include "SchedulerConfig.h"

namespace Squirrel {

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
}
