#include "Configuration.h"

Configuration::Configuration()
{
	renderConfig.setup();
	schedulerConfig.setup();
	audioConfig.setup();
}

Configuration& Configuration::getInstance()
{
	static Configuration instance;
	return instance;
}
