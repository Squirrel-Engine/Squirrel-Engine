#include "include/J_Window_CreateWindow.h"




namespace Squirrel
{
	J_Window_CreateWindow::J_Window_CreateWindow():Job()
	{
		
	}

	//I am not sure about the necessity of the Setup
	void J_Window_CreateWindow::mount()
	{
		height = renderStore.SCREEN_HEIGHT;
		width = renderStore.SCREEN_WIDTH;
		windowName = renderStore.WINDOW_NAME;
		window = renderStore.WINDOW;

		windowManager = new WindowManager(width, height, windowName);
	}

	void J_Window_CreateWindow::run()
	{
		mount();
		// ************
		std::cout << "Window_CreateWindow Job run" << std::endl;
		windowManager->createWindow();
		window = windowManager->getWindow();
		createJob(EJobClass::Window_RenderWindow);
		// ************
		unmount();
	}

	void J_Window_CreateWindow::unmount()
	{
		renderStore.SCREEN_HEIGHT = height;
		renderStore.SCREEN_WIDTH = width;
		renderStore.WINDOW_NAME = windowName;
		renderStore.WINDOW = window;
		std::cout << &renderStore << std::endl;
	}

}
