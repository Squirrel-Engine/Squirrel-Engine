#include "Nut.h"
#include <iostream>
#include "InterfaceFactory.h"
#include "NJ_InitializeFrame.h"
#include "Configuration.h"

std::mutex mtx;

Nut::Nut()
{
}

void Nut::startScheduler()
{
	if (Configuration::getInstance().schedulerConfig.mtMode == true)
	{
		while (true)
		{
			int threadCount = 8;
			std::vector<std::thread> threadPool;
			jobQueueHighOrder.push(new NJ_InitializeFrame());

			// Frame Loop
			while (!jobQueueHighOrder.empty())
			{
				jobQueueHighOrder.front()->run();
				free(jobQueueHighOrder.front());
				jobQueueHighOrder.pop();
				while (!jobQueueLowOrder.empty())
				{
					for (int i = 0; i < threadCount; i++)
					{
						threadPool.push_back(std::thread([this] { schedular(); }));
					}
					std::for_each(threadPool.begin(), threadPool.end(), [](std::thread& t)
					{
							t.join();
					});
				}
			}
		}
	}else{
		while (true)
		{
			jobQueueHighOrder.push(new NJ_InitializeFrame());

			// Frame Loop
			while (!jobQueueHighOrder.empty())
			{
				jobQueueHighOrder.front()->run();
				free(jobQueueHighOrder.front());
				jobQueueHighOrder.pop();
				while (!jobQueueLowOrder.empty())
				{
					jobQueueLowOrder.front()->run();
					free(jobQueueLowOrder.front());
					jobQueueLowOrder.pop();
				}
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

void Nut::schedular()
{
	mtx.lock();
	if (!jobQueueLowOrder.empty())
	{
		NJob* job;
		job = jobQueueLowOrder.front();
		job->run();
		jobQueueLowOrder.pop();
	}
	mtx.unlock();
}

void Nut::submitJob(NJob& job, EQueueOrder order)
{
	switch (order)
	{
	case EQueueOrder::LOW_ORDER:
		jobQueueLowOrder.push(&job);
		break;
	case EQueueOrder::HIGH_ORDER:
		jobQueueHighOrder.push(&job);
		break;
	}
}
