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
	if (glfwGetKey(furWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->W_HOLD();
	}
	if (glfwGetKey(furWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->S_HOLD();
	}
	if (glfwGetKey(furWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->A_HOLD();
	}
	if (glfwGetKey(furWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->D_HOLD();
	}
	if (glfwGetKey(furWindow, GLFW_KEY_Q) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->Q_HOLD();
	}
	if (glfwGetKey(furWindow, GLFW_KEY_E) == GLFW_PRESS)
	{
		getInterface<IP_Interface>().controlSchematic->E_HOLD();
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
