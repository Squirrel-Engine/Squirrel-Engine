#pragma once
#include "WindowManager.h"
#include "Store.h"
#include "Job.h"
#include "JobFactory.h"
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

		// Objects
		WindowManager* windowManager;
	};
}
