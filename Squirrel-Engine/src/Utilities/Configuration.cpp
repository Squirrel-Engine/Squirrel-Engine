#include "Configuration.h"

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
