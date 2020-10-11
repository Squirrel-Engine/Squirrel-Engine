#include "include/JobFactory.h"

namespace Squirrel
{
	void JobFactory::createJob(EJobClass jclass)
	{
		Job* jobCreate = new J_Window_CreateWindow();
		Job* jobRender = new J_Window_RenderWindow();
		switch (jclass)
		{
		case EJobClass::Window_CreateWindow:
			
			MockStateManager::getInstance()->JobQueue.push(jobCreate);
			break;
		case EJobClass::Window_RenderWindow:
			
			MockStateManager::getInstance()->JobQueue.push(jobRender);
			break;
		}
	}
}
