#pragma once
#include "RenderConfig.h"
#include "SchedulerConfig.h"

namespace Squirrel {

	class Configuration
	{
	private:
		Configuration();
		static Configuration* instance;

	public:
		static Configuration* getInstance();
		RenderConfig renderConfig;
		SchedulerConfig schedulerConfig;
	};
}
