#pragma once
#include <queue>
#include "EQueueOrder.h"
#include "NJob.h"

namespace Squirrel
{
	class Nut
	{
	public:
		Nut();
		void startScheduler();
		void stopScheduler();
		void pauseScheduler();

		void submitJob(NJob* job, EQueueOrder order);
	private:
		std::queue<NJob*> jobQueueLowOrder;
		std::queue<NJob*> jobQueueHighOrder;
	};
}
