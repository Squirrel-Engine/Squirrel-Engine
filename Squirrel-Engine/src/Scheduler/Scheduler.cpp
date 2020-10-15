#include "include/Scheduler.h"

namespace Squirrel
{
	void Squirrel::Scheduler::start()
	{
		while (true)
		{
			//Get Job From Queue
			if (!jobQueue.lowPriJobQueue.empty())
			{
				jobQueue.lowPriJobQueue.front()->run();
				jobQueue.lowPriJobQueue.pop();
			}
			else
			{
				std::cout << "Job Queue is Empty" << std::endl;
			}

		}
	}

}
