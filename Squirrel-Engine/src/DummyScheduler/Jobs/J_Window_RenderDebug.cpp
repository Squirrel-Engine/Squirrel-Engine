#include "include/J_Window_RenderDebug.h"

#include "include/InterfaceFactory.h"

namespace Squirrel
{
	J_Window_RenderDebug::J_Window_RenderDebug()
	{
		
	}

	void J_Window_RenderDebug::mount()
	{
	}

	void J_Window_RenderDebug::run()
	{
		mount();
		InterfaceFactory::getInstance()->getRDInterface().render();
		unmount();
	}

	void J_Window_RenderDebug::unmount()
	{
	}



}
