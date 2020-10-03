#pragma once
#include <iostream>
#include<map>
#include "../../../include/json.hpp"
#include <fstream>
namespace Squirrel {
	class JSONParser{
	public:
		JSONParser(std::string path);
		nlohmann::json parseFile_json();
		std::map<std::string, std::string> parseFile_map();
	private:
		std::string parsePath;
	};
}
