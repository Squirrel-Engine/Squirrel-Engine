#include "include/Scheduler.h"

namespace Squirrel
{
	void Squirrel::Scheduler::start()
	{
		while (true)
		{
			//Get Job From Queue
			if (!lowPriJobQueue.empty())
			{
				lowPriJobQueue.front()->run();
				lowPriJobQueue.pop();
			}
			else
			{
				std::cout << "Job Queue is Empty" << std::endl;
			}

		}
	}

}
