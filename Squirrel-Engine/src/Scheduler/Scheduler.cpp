#include "include/Scheduler.h"

void Squirrel::Scheduler::Start()
{
	while(true)
	{
		//Get Job From Queue
		if(!MockStateManager::getInstance()->JobQueue.empty())
		{
			MockStateManager::getInstance()->JobQueue.front()->Run();
			MockStateManager::getInstance()->JobQueue.pop();
		}else
		{
			std::cout <<  "Job Queue is Empty" << std::endl;
		}

	}
}
