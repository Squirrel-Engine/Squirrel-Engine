#include "NJ_Input.h"

#include <iostream>

#include "InterfaceFactory.h"
#include "NJ_InitializeSimulation.h"

namespace Squirrel
{
	NJ_Input::NJ_Input()
	{
		
	}

	void NJ_Input::run()
	{
		std::cout << "!! Input !!" << std::endl;
		InterfaceFactory::getInstance().getMTInterface().submitJob(new NJ_InitializeSimulation(), EQueueOrder::LOW_ORDER);
	}

	void NJ_Input::mount()
	{

	}

	void NJ_Input::unmount()
	{

	}
}




