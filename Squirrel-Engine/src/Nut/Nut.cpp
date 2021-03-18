#include "Nut.h"

#include <iostream>

#include "NJ_InitializeFrame.h"


enum class EQUEUE_ORDER
{
	LOW_ORDER,
	HIGHT_ORDER
};

namespace Squirrel
{
	Nut::Nut()
	{
	}

	void Nut::startScheduler()
	{

		//Game Loop
		while (true)
		{
			jobQueueHighOrder.push(new NJ_InitializeFrame());
			// Frame Loop
			while (jobQueueHighOrder.size() != 0)
			{
				jobQueueHighOrder.front()->run();
				free(jobQueueHighOrder.front());
				jobQueueHighOrder.pop();
				while(jobQueueLowOrder.size() != 0)
				{
					jobQueueLowOrder.front()->run();
					free(jobQueueLowOrder.front());
					jobQueueLowOrder.pop();
					
				}

			}

		}
	}

	void Nut::stopScheduler()
	{
	}

	void Nut::pauseScheduler()
	{
	}

	void Nut::submitJob(NJob* job, EQueueOrder order)
	{
		switch (order)
		{
		case EQueueOrder::LOW_ORDER:
			jobQueueLowOrder.push(job);
			break;
		case EQueueOrder::HIGH_ORDER:
			jobQueueHighOrder.push(job);
			break;
		}
	}

}
