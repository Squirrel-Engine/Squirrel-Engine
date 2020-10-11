#pragma once
#include "Job.h"
#include "WindowManager.h"
namespace Squirrel
{
	class J_Window_CreateWindow:public Job
	{
	public:
		J_Window_CreateWindow();
		void Setup() override;
		void Run() override;
	private:
		int width;
		int height;
		std::string windowName;
	};
}
