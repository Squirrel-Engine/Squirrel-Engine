#include "../../../include/JSONConfigurator.h"


using json = nlohmann::json;
namespace Squirrel {
	std::map<std::string, std::string> JSONConfigurator::parseConfigurations() {
		std::ifstream i(configPath);		
		json j;
		j << i;
		return j;
		/*
		std::map<std::string, std::string> configMap = j;
		for (const auto& x : configMap) {
			std::cout << x.first << ": " << x.second << "\n";
		}
		return configMap;
		*/
	}
	JSONConfigurator::JSONConfigurator(std::string path) {
		configPath = path;
	}
	void JSONConfigurator::setConfigurations() {

	}
}