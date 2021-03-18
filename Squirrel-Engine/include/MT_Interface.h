#pragma once
#include "DummyScheduler.h"
#include "EQueueOrder.h"
#include "Nut.h"

namespace Squirrel
{
	class MT_Interface
	{
	public:
		MT_Interface();
		void startScheduler();
		void stopScheduler();
		void pauseScheduler();

		void submitJob(NJob* job, EQueueOrder order);

	private:
		// Options
		bool renderDebug;

		// Schedulers
		DummyScheduler* dummyScheduler;
		Nut* nut;
	};


}
