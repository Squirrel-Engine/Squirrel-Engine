#include "InputStore.h"
#include "InterfaceFactory.h"
namespace Squirrel {
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
			InterfaceFactory::getInstance().getIPInterface().controlSchematic->Key_SPACE();
		}
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		//getting cursor position
		int width, height;
		glfwGetCursorPos(window, &xpos, &ypos);
		glfwGetFramebufferSize(window, &width, &height);
		//Normalization Between [-1, 1] https://stats.stackexchange.com/questions/178626/how-to-normalize-data-between-1-and-1
		InterfaceFactory::getInstance().getIPInterface().mouseX = 2*((xpos - 1) / (width + 1)) - 1;
		InterfaceFactory::getInstance().getIPInterface().mouseY = 2*((ypos - 1) / (height + 1))-1;


		InterfaceFactory::getInstance().getIPInterface().controlSchematic->Mouse_Movement();
	}
}
