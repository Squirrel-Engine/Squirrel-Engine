#pragma once
#include"IConfigurator.h"
#include<map>
#include "../../../include/json.hpp"
#include <fstream>
namespace Squirrel {
	class JSONConfigurator:IConfigurator {
	public:
		JSONConfigurator(std::string path);
		std::map<std::string, std::string> parseConfigurations();
		void setConfigurations();
	private:
		std::string configPath;
	};
}
