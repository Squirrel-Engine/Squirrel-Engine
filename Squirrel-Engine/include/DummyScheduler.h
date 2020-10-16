#pragma once
#include <iostream>
#include "Jobs.h"
namespace Squirrel
{
	enum class ESchedulerState{
		RUNNING,
		PAUSED,
		STOPPED
	};

	enum class ESchedulerMode
	{
		OPERATIONAL,
		RENDER_DEBUG
	};

	class DummyScheduler
	{
	public:
		DummyScheduler();
		DummyScheduler(ESchedulerMode mode);
		void startScheduler();
		void stopScheduler();
		void pauseScheduler();
		
	private:
		ESchedulerState schedulerState;
		std::queue<Job*> jobQueue;
		ESchedulerMode schedulerMode;
	};
}


