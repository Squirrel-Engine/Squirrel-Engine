#include "Nut.h"

#include <iostream>

#include "NJ_InitializeFrame.h"

namespace Squirrel
{
	Nut::Nut()
	{
	}

	void Nut::startScheduler()
	{

		//Game Loop
		while (true)
		{
			jobQueue.push(new NJ_InitializeFrame());
			// Frame Loop
			while (true)
			{
				if (jobQueue.size() == 0)
				{
					break;
				}
				jobQueue.front()->run();
				jobQueue.pop();
			}

		}
	}

	void Nut::stopScheduler()
	{
	}

	void Nut::pauseScheduler()
	{
	}

	void Nut::submitJob(NJob* job)
	{
		jobQueue.push(job);
	}
}
