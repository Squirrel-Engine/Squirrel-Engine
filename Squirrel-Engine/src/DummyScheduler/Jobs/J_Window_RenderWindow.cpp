#include "include/J_Window_RenderWindow.h"

namespace Squirrel
{
	J_Window_RenderWindow::J_Window_RenderWindow():Job()
	{
		
	}

	void J_Window_RenderWindow::mount()
	{


		windowManager = new WindowManager();
	}

	void J_Window_RenderWindow::run()
	{
		mount();

		unmount();
	}

	void J_Window_RenderWindow::unmount()
	{
		
	}

}
