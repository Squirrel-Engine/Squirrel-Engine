#pragma once
#include "DummyScheduler.h"

namespace Squirrel
{
	class MT_Interface
	{
	public:
		MT_Interface();
		void startScheduler();
		void stopScheduler();
		void pauseScheduler();

	private:
		// Options
		bool renderDebug;

		// Schedulers
		DummyScheduler* dummyScheduler;
	};


}
