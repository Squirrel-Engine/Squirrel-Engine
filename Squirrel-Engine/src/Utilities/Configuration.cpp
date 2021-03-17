#include "Configuration.h"

namespace Squirrel {
	Configuration::Configuration()
	{
		renderConfig.setup();
		schedulerConfig.setup();
	}
	
	Configuration& Configuration::getInstance()
	{
		static Configuration instance;
		return instance;
	}
}
