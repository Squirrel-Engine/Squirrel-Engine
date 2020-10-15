#include "include/JobFactory.h"

namespace Squirrel
{
	void createJob(EJobClass jclass)
	{
		JobQueue jobQueue;
		switch (jclass)
		{
		case EJobClass::Window_CreateWindow:
			jobQueue.lowPriJobQueue.push(new J_Window_CreateWindow());
			break;
		case EJobClass::Window_RenderWindow:
			jobQueue.lowPriJobQueue.push(new J_Window_RenderWindow);
			break;
		}
	}
}
