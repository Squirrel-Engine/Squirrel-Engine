#include "NJ_Input.h"

namespace Squirrel
{
	NJ_Input::NJ_Input()
	{
		
	}

	void NJ_Input::run()
	{
		InterfaceFactory::getInstance().getIPInterface().execInput();
	}

	void NJ_Input::mount()
	{

	}

	void NJ_Input::unmount()
	{

	}
}




