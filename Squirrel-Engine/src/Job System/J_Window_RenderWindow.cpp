#include "include/J_Window_RenderWindow.h"

namespace Squirrel
{
	J_Window_RenderWindow::J_Window_RenderWindow():Job()
	{
		
	}

	void J_Window_RenderWindow::Setup()
	{
		
	}

	void J_Window_RenderWindow::Run()
	{
		std::cout << "RenderWindow::Run()" << std::endl;
		Setup();
		WindowManager windowManager = WindowManager();
		windowManager.renderWindow(MockStateManager::getInstance()->window);
		JobFactory jobFac = JobFactory();
		jobFac.createJob(EJobClass::Window_RenderWindow);

	}
}
