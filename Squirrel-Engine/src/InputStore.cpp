#include "InputStore.h"
#include "InterfaceFactory.h"
namespace Squirrel {
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
			InterfaceFactory::getInstance().getIPInterface().controlSchematic->Key_SPACE();
		}
	}

}
