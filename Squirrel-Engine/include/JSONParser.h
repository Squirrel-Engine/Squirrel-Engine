#pragma once
#include"IParser.h"
#include<map>
#include "../../../include/json.hpp"
#include <fstream>
namespace Squirrel {
	class JSONParser: IParser {
	public:
		JSONParser(std::string path);
		std::map<std::string, std::string> parseFiles();
	private:
		std::string parsePath;
	};
}
