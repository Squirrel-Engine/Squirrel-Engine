#pragma once
//#include "Jobs.h"
#include "J_Window_CreateWindow.h"
namespace Squirrel
{
	class JobFactory
	{
	public:
		Job* createJob(JobClass jclass);
	};
}
