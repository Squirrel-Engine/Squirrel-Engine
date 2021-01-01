#pragma once
#include "IStore.h"

namespace Squirrel
{
	class LevelStore : IStore
	{
		
	public:
		LevelStore();
		int x;
		void setupStore() override;
	};
}
