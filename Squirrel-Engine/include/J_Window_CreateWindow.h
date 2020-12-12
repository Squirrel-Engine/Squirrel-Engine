#pragma once
#include "Window.h"
#include "Job.h"
#include "JobFactory.h"
#include <iostream>
#include <string.h>
namespace Squirrel
{
	class J_Window_CreateWindow : public Job
	{
	public:
		J_Window_CreateWindow();
		void mount() override;
		void unmount() override;
		void run() override;
	private:
		// Properities
		int width;
		int height;
		std::string windowName;
		Window window;
	};
}
