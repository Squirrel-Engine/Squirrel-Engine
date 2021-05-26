#include "Utilities.h"

char* Utilities::convertStdStringToConst(std::string str)
{
	auto cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}

