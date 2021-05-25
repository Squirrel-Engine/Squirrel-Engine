#pragma once
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <map>

class JSONParser
{
public:
	JSONParser(std::string path);
	nlohmann::json parseFile_json();
	std::map<std::string, std::string> parseFile_map();
private:
	std::string parsePath;
};
