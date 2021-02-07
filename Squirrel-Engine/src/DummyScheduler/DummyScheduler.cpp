#include "DummyScheduler.h"

namespace Squirrel
{
	DummyScheduler::DummyScheduler()
	{
		
	}

	DummyScheduler::DummyScheduler(ESchedulerMode mode)
	{
		schedulerState = ESchedulerState::RUNNING;
		switch (mode)
		{
		case ESchedulerMode::OPERATIONAL:
			schedulerMode = ESchedulerMode::OPERATIONAL;
			jobQueue.push(new J_Window_CreateWindow);
			break;
		case ESchedulerMode::RENDER_DEBUG:
			schedulerMode = ESchedulerMode::RENDER_DEBUG;
			break;

		}
	}


	void DummyScheduler::startScheduler()
	{
			switch (schedulerMode)
			{
			case ESchedulerMode::OPERATIONAL:
				while (true)
				{
					if (schedulerState == ESchedulerState::RUNNING) {
						if (!jobQueue.empty())
						{
							jobQueue.front()->run();
							jobQueue.pop();
						}
						else
						{
							std::cout << "Job Queue is Empty" << std::endl;
						}
					}
					else if (schedulerState == ESchedulerState::PAUSED) {
						std::cout << "Paused" << std::endl;
					}
					else if (schedulerState == ESchedulerState::STOPPED) {
						std::cout << "HALT" << std::endl;
						break;
					}
				}
			case ESchedulerMode::RENDER_DEBUG:
				while (true)
				{
					if (schedulerState == ESchedulerState::RUNNING) {
						jobQueue.push(new J_Window_RenderDebug);
						jobQueue.front()->run();
						free(jobQueue.front());
						jobQueue.pop();
					}
					else if (schedulerState == ESchedulerState::PAUSED) {
						std::cout << "Paused" << std::endl;
					}
					else if (schedulerState == ESchedulerState::STOPPED) {
						std::cout << "HALT" << std::endl;
						break;
					}
				}
			default:
				std::cout << "No Valid Mode Defination" << std::endl;
		}
		
	}

	void DummyScheduler::pauseScheduler()
	{
		schedulerState = ESchedulerState::PAUSED;
	}

	void DummyScheduler::stopScheduler()
	{
		schedulerState = ESchedulerState::STOPPED;
	}



}
