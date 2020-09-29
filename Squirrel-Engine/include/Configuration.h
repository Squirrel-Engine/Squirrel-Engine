#pragma once

namespace Squirrel {

	class Configuration
	{
	private:
		Configuration();
		static Configuration* instance;

	public:
		static Configuration* getInstance();
	};
}