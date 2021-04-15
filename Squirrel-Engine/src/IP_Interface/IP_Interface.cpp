#include "IP_Interface.h"


namespace Squirrel
{
	IP_Interface::IP_Interface()
	{

	}

	void IP_Interface::execInput()
	{
		//glfwSetWindowUserPointer(furWindow, this);
		glfwSetKeyCallback(furWindow, key_callback);
		glfwPollEvents();
	}



	void IP_Interface::setControlSchema(ControlSchematic* _controlSchema)
	{
		controlSchematic = _controlSchema;
	}


}
