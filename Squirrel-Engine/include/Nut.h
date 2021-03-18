#pragma once
#include <queue>
#include "EQueueOrder.h"
#include "NJob.h"
#include <mutex>


//std::mutex g_pages_mutex;
namespace Squirrel
{
	class Nut
	{
	public:
		Nut();
		void startScheduler();
		void stopScheduler();
		void pauseScheduler();
		NJob* schedular();
		void threadProcess();
		void submitJob(NJob& job, EQueueOrder order);
	private:
		std::queue<NJob*> jobQueueLowOrder;
		std::queue<NJob*> jobQueueHighOrder;
	};
}
