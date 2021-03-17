#pragma once
#include <queue>

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

		void submitJob(NJob* job);
	private:
		std::queue<NJob*> jobQueue;
	};
}
