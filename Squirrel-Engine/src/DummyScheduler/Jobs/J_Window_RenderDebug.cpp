#include "include/J_Window_RenderDebug.h"
#include "include/InterfaceFactory.h"

namespace Squirrel
{
	J_Window_RenderDebug::J_Window_RenderDebug()
	{
		jobCategory = EJobCategory::Render;
		jobPriority = EJobPriority::Medium;
	}

	void J_Window_RenderDebug::mount() 
	{
	}

	void J_Window_RenderDebug::run()
	{
		mount();
		InterfaceFactory::getInstance()->getRDInterface()->addActorToRenderQueue(*objcet);
		unmount();
	}

	void J_Window_RenderDebug::unmount()
	{

	}
}
