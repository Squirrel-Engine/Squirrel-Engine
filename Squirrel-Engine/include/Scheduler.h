#pragma once
#include <iostream>
#include "JobQueue.h"
namespace Squirrel
{
	class Scheduler
	{
	public:
		Scheduler() {}
		void start();
	private:
		JobQueue jobQueue;
	};
}


