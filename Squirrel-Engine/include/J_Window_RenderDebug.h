#pragma once
#include "JobFactory.h"
#include "Job.h"

namespace Squirrel
{
	class J_Window_RenderDebug : public Job
	{
	public:
		J_Window_RenderDebug();
		void mount() override;
		void unmount() override;
		void run() override;
	private:
		int jobClassID;
		EJobCategory jobCategory;
		EJobPriority jobPriority;
	};
}
