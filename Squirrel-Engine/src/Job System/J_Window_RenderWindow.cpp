#include "include/J_Window_RenderWindow.h"

namespace Squirrel
{
	J_Window_RenderWindow::J_Window_RenderWindow():Job()
	{
		
	}

	void J_Window_RenderWindow::mount()
	{
		window = renderStore->WINDOW;

		windowManager = new WindowManager();
	}

	void J_Window_RenderWindow::run()
	{
		mount();
		windowManager->renderWindow(window);
		jobFactory->createJob(EJobClass::Window_RenderWindow);
		unmount();
	}

	void J_Window_RenderWindow::unmount()
	{
		
	}

}
