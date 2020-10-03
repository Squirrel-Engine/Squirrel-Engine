#pragma once
#include "RenderConfig.h"

namespace Squirrel {

	class Configuration
	{
	private:
		Configuration();
		static Configuration* instance;

	public:
		static Configuration* getInstance();
		RenderConfig renderConfig;
	};
}
