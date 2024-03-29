#include "Nut.h"
#include "InterfaceFactory.h"
#include "NJ_InitializeFrame.h"
#include "Configuration.h"

std::mutex mtx;

Nut::Nut()
{
	multithreded = Configuration::getInstance().schedulerConfig.mtMode;
}

void Nut::startScheduler()
{
	if(multithreded){
		int threadCount = 4;					//std::thread::hardware_concurrency();
		std::vector<std::thread> threadPool;

		for (int i = 0; i < threadCount; i++)
		{
			threadPool.push_back(std::thread(&Nut::threadPoolProcess, this));
		}

		for (int i = 0; i < threadCount; i++)
		{
			threadPool.at(i).detach();
		}
		while (true)
		{
			submitJob(*new NJ_InitializeFrame(), EQueueOrder::HIGH_ORDER);

			while (!jobQueueHighOrder.empty())
			{
				if (jobQueueLowOrder.empty())
				{
					processHighOrder();
				}
			}
		}
	}
	else {
		while (true)
		{
			submitJob(*new NJ_InitializeFrame(), EQueueOrder::HIGH_ORDER);
			// Frame Loop
			while (!jobQueueHighOrder.empty())
			{
				processHighOrder();
				while (!jobQueueLowOrder.empty())
				{
					processLowOrder();
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

void Nut::threadPoolProcess()
{
	while (true)
	{
		NJob* job;
		job = threadPoolSchedular();
		if (job){
			job->run();
		}
	}
}

NJob* Nut::threadPoolSchedular()
{
	mtx.lock();
	NJob* job = nullptr;
	if (!jobQueueLowOrder.empty())
	{
		job = jobQueueLowOrder.front();
		jobQueueLowOrder.pop();
	}
	mtx.unlock();
	return job;
}

void Nut::submitJob(NJob& job, EQueueOrder order)
{
	if (order == EQueueOrder::HIGH_ORDER && multithreded) {
		mtx.lock();
		jobQueueHighOrder.push(&job);
		mtx.unlock();
	}
	else if (order == EQueueOrder::HIGH_ORDER && !multithreded) {
		jobQueueHighOrder.push(&job);
	}
	else if (order == EQueueOrder::LOW_ORDER && multithreded) {
		mtx.lock();
		jobQueueLowOrder.push(&job);
		mtx.unlock();
	}
	else if (order == EQueueOrder::LOW_ORDER && !multithreded) {
		jobQueueLowOrder.push(&job);
	}
}

void Nut::processHighOrder() {
	jobQueueHighOrder.front()->run();
	free(jobQueueHighOrder.front());
	jobQueueHighOrder.pop();
}

void Nut::processLowOrder() {
	jobQueueLowOrder.front()->run();
	free(jobQueueLowOrder.front());
	jobQueueLowOrder.pop();
}