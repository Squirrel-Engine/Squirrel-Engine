#include "include/J_Window_CreateWindow.h"

namespace Squirrel
{
	J_Window_CreateWindow::J_Window_CreateWindow()
	{
		
	}

	//I am not sure about the necessity of the Setup
	void J_Window_CreateWindow::mount()
	{
	}

	void J_Window_CreateWindow::run()
	{
		mount();
		// ************
		std::cout << "Create Window" << std::endl;
		
		// ************
		unmount();
	}

	void J_Window_CreateWindow::unmount()
	{

	}

}
