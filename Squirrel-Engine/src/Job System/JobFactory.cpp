#include "include/JobFactory.h"


void Squirrel::JobFactory::createJob(EJobClass jclass)
{
	switch (jclass)
	{
	case EJobClass::Window_CreateWindow:
		lowPriJobQueue.push(new J_Window_CreateWindow());
		break;
	case EJobClass::Window_RenderWindow:
		lowPriJobQueue.push(new J_Window_RenderWindow);
		break;
	}
}



/*
namespace Squirrel
{
	void JobFactory::createJob(EJobClass jclass)
	{

		switch (jclass)
		{
		case EJobClass::Window_CreateWindow:
			lowPriJobQueue.push(new J_Window_CreateWindow());
			break;
		case EJobClass::Window_RenderWindow:
			lowPriJobQueue.push(new J_Window_RenderWindow);
			break;
		}
	}
}
*/