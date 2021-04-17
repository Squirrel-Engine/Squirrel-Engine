#include "Utilities.h"

namespace Squirrel
{
	char* convertStdStringToConst(std::string str)
	{
		auto cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
}
