#include "InputStore.h"
#include "InterfaceFactory.h"
#include "pch.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_SPACE:
		if (action == GLFW_PRESS)
		{
			getInterface<IP_Interface>().controlSchematic->Key_SPACE_PRESS();
		}
		else if (action == GLFW_RELEASE)
		{
			getInterface<IP_Interface>().controlSchematic->Key_SPACE_RELEASE();
		}
	default:
		break;
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	//getting cursor position
	int width, height;
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwGetFramebufferSize(window, &width, &height);
	//Normalization Between [-1, 1] https://stats.stackexchange.com/questions/178626/how-to-normalize-data-between-1-and-1
	getInterface<IP_Interface>().mouseX = 2 * ((xpos - 1) / (width + 1)) - 1;
	getInterface<IP_Interface>().mouseY = 2 * ((ypos - 1) / (height + 1)) - 1;

	getInterface<IP_Interface>().controlSchematic->Mouse_Movement();
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	getInterface<IP_Interface>().scrollX = xoffset;
	getInterface<IP_Interface>().scrollY = yoffset;
	getInterface<IP_Interface>().controlSchematic->ScrollMovement();
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
		if (action == GLFW_PRESS)
		{
			getInterface<IP_Interface>().controlSchematic->Mouse_Left_PRESS();
		}
		else if (action == GLFW_RELEASE)
		{
			getInterface<IP_Interface>().controlSchematic->Mouse_Left_RELEASE();
		}
	case GLFW_MOUSE_BUTTON_RIGHT:
		if (action == GLFW_PRESS)
		{
			getInterface<IP_Interface>().controlSchematic->Mouse_Right_PRESS();
		}
		else if (action == GLFW_RELEASE)
		{
			getInterface<IP_Interface>().controlSchematic->Mouse_Right_RELEASE();
		}
	default:
		break;
	}
}
