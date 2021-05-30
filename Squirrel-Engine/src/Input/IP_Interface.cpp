#include "IP_Interface.h"

IP_Interface::IP_Interface()
{
}

void IP_Interface::execInput()
{
	//glfwSetWindowUserPointer(furWindow, this);
	glfwSetKeyCallback(furWindow, key_callback);
	glfwSetInputMode(furWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(furWindow, cursor_position_callback);
	glfwSetScrollCallback(furWindow, scroll_callback);
	glfwSetMouseButtonCallback(furWindow, mouse_button_callback);
	glfwPollEvents();
}


void IP_Interface::setControlSchema(ControlSchematic* _controlSchema)
{
	controlSchematic = _controlSchema;
}
