#pragma once
#include "JobFactory.h"
#include "Job.h"
namespace Squirrel
{
	class J_Window_RenderWindow : public Job
	{
	public:
		J_Window_RenderWindow();
		~J_Window_RenderWindow();
		void mount() override;
		void unmount() override;
		void run() override;
	private:
		Window window;
	};
}

