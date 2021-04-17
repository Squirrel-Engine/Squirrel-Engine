#pragma once
#include <iostream>

namespace Squirrel
{
	class Audio
	{
	public:
		Audio(std::string filename);
		FILE* audioObject;
	};
}



