#include "NJ_Input.h"

namespace Squirrel
{
	NJ_Input::NJ_Input()
	{
		
	}

	void NJ_Input::run()
	{
		InterfaceFactory::getInstance().getIPInterface().execInput();
		if (glfwGetKey(furWindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
			InterfaceFactory::getInstance().getIPInterface().controlSchematic->Key_Space_HOLD();
		}
		if (glfwGetMouseButton(furWindow, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			InterfaceFactory::getInstance().getIPInterface().controlSchematic->Mouse_Left_HOLD();
		}
		if (glfwGetMouseButton(furWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
			InterfaceFactory::getInstance().getIPInterface().controlSchematic->Mouse_Right_HOLD();
		}
		//std::cout << InterfaceFactory::getInstance().getIPInterface().isUpKeyHeldDown << std::endl;
	}

	void NJ_Input::mount()
	{

	}

	void NJ_Input::unmount()
	{

	}
}




