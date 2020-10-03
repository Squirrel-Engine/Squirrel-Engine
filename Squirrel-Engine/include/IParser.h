#pragma once
#include<iostream>
#include <map>

namespace Squirrel {
	class IParser
	{
	public:
		virtual std::map<std::string, std::string> parseFiles() = 0;
	private:
		std::map<std::string, std::string> fileMap;
	};
}
