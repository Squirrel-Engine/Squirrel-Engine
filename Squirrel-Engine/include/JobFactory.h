#pragma once
#include "JobQueue.h"
#include "Jobs.h"

namespace Squirrel
{
	struct JobFactory
	{
		void createJob(EJobClass jclass);
	} *jobFactory;
	
}


/*
namespace Squirrel
{
	class JobFactory
	{
	public:
		void createJob(EJobClass jclass);
	};
}

*/