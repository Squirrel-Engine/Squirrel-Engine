#pragma once
#include "Job.h"
#include <queue>


namespace Squirrel
{
	class JobQueue
	{
	public:
		static std::queue<Job*> lowPriJobQueue;
		static std::queue<Job*> midPriJobQueue;
		static std::queue<Job*> highPriJobQueue;
		static std::queue<Job*> criticalPriJobQueue;
	};

}

