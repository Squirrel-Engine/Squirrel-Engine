#include "NJ_Input.h"
#include "InterfaceFactory.h"
#include "NJ_InitializeSimulation.h"

NJ_Input::NJ_Input()
{
}


void NJ_Input::run()
{
	getInterface<IP_Interface>().execInput();
	if (glfwGetKey(furWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->Key_Space_HOLD();
	}
	if (glfwGetMouseButton(furWindow, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->Mouse_Left_HOLD();
	}
	if (glfwGetMouseButton(furWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->Mouse_Right_HOLD();
	}
}


void NJ_Input::mount()
{
}

void NJ_Input::unmount()
{
}
