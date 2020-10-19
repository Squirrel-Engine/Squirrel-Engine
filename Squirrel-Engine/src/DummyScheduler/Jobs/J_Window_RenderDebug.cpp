#include "include/J_Window_RenderDebug.h"

namespace Squirrel
{
	J_Window_RenderDebug::J_Window_RenderDebug():Job()
	{
		
	}

	void J_Window_RenderDebug::mount()
	{


		windowManager = new WindowManager();
	}

	void J_Window_RenderDebug::run()
	{
		mount();
		while (true)
		{
			std::cout << "Render Debug" << std::endl;
		}
		unmount();
	}

	void J_Window_RenderDebug::unmount()
	{
		
	}

}
