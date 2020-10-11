#pragma once
#include "Job.h"
#include "MockStateManager.h"
#include "JobFactory.h"
namespace Squirrel
{
	class J_Window_RenderWindow : public Job
	{
	public:
		J_Window_RenderWindow();
		void Setup() override;
		void Run() override;
	};
}

