#pragma once
#include "DummyScheduler.h"
#include "LevelStore.h"

namespace Squirrel
{
	class GM_Interface
	{
	public:
		GM_Interface();
		LevelStore* levelStore;
	};


}
