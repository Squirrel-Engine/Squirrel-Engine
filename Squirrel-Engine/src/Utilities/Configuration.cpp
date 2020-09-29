#include "../../../include/Configuration.h"

namespace Squirrel {

	Configuration* Configuration::instance = 0;
	Configuration* Configuration::getInstance()
	{
		if (instance == 0)
		{
			instance = new Configuration();
		}
		return instance;
	}
}
