#include "Nut.h"
#include <iostream>
#include "InterfaceFactory.h"
#include "NJ_InitializeFrame.h"
#include "Configuration.h"

namespace Squirrel
{
	std::mutex g_pages_mutex;
	Nut::Nut()
	{
	}
	
	void Nut::threadProcess()
	{
		NJob* job;
		while (true)
		{
			job = schedular();
			if (job == nullptr)
			{

			}
			else
			{
				job->run();
				free(job);
			}
		}
	}
	
	void Nut::startScheduler()
	{
		if(Configuration::getInstance().schedulerConfig.mtMode == true)
		{
			int threadCount = 8;
			std::vector<std::thread> threadPool;

			for (int i = 0; i < threadCount; i++)
			{
				threadPool.push_back(std::thread(&Nut::threadProcess, this));
			}

			for (int i = 0; i < threadCount; i++)
			{
				threadPool.at(i).detach();
			}
			while (true)
			{
				jobQueueHighOrder.push(new NJ_InitializeFrame());
				while (jobQueueHighOrder.size() != 0)
				{
					jobQueueHighOrder.front()->run();
					free(jobQueueHighOrder.front());
					jobQueueHighOrder.pop();
				}
			}

		}else
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
					while (jobQueueLowOrder.size() != 0)
					{
						jobQueueLowOrder.front()->run();
						free(jobQueueLowOrder.front());
						jobQueueLowOrder.pop();
					}
				}
				std::queue<NJob*> empty;
				std::swap(jobQueueHighOrder, empty);
				std::swap(jobQueueLowOrder, empty);
			}
		}


	}

	void Nut::stopScheduler()
	{
	}

	void Nut::pauseScheduler()
	{
	}

	NJob* Nut::schedular()
	{
		std::lock_guard<std::mutex> guard(g_pages_mutex);
		NJob* job;
		if(jobQueueLowOrder.empty() == true)
		{
			job = nullptr;
		}else
		{
			job = jobQueueLowOrder.front();
			jobQueueLowOrder.pop();
		}
		return job;
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

}



