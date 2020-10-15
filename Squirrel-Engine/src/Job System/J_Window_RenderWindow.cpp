#include "include/J_Window_RenderWindow.h"

namespace Squirrel
{
	J_Window_RenderWindow::J_Window_RenderWindow():Job()
	{
		
	}

	void J_Window_RenderWindow::mount()
	{
		window = renderStore.WINDOW;

		windowManager = new WindowManager();
	}

	void J_Window_RenderWindow::run()
	{
		mount();
		std::cout << &renderStore << std::endl;
		windowManager->renderWindow(window);
		createJob(EJobClass::Window_RenderWindow);
		unmount();
	}

	void J_Window_RenderWindow::unmount()
	{
		
	}

}
