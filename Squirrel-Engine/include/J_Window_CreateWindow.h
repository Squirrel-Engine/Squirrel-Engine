#pragma once
#include "Job.h"

namespace Squirrel
{
	class J_Window_CreateWindow:Job
	{
	public:
		J_Window_CreateWindow();
		void Run() override;
	};
}
