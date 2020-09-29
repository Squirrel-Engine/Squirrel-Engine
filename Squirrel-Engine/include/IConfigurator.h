#pragma once
#include<iostream>
#include <map>

namespace Squirrel {
	class IConfigurator
	{
	public:
		virtual std::map<std::string, std::string> parseConfigurations() = 0;
		virtual void setConfigurations() = 0;
	private:
		std::map<std::string, std::string> configurationMap;
	};
}
