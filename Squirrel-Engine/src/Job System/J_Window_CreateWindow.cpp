#include "include/J_Window_CreateWindow.h"
#include "include/MockStateManager.h"
namespace Squirrel
{
	J_Window_CreateWindow::J_Window_CreateWindow():Job()
	{
		
	}

	void J_Window_CreateWindow::Setup()
	{
		height = MockStateManager::getInstance()->height;
		width = MockStateManager::getInstance()->width;
		windowName = MockStateManager::getInstance()->windowName;
	}

	void J_Window_CreateWindow::Run()
	{
		Setup();
		std::cout << "Window_CreateWindow Job Run" << std::endl;
		WindowManager manager(width,height,windowName);
		manager.createWindow();
		MockStateManager::getInstance()->window = manager.getWindow();
		JobFactory jobFac = JobFactory();
		jobFac.createJob(EJobClass::Window_RenderWindow);
		
	}
}
