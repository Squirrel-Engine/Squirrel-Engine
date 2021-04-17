#include "ControlSchema/TestControlSchema.h"
#include <typeinfo>


void TestControlSchema::Key_SPACE_RELEASE()
{
	std::cout << "RELEASE" << std::endl;
}

void TestControlSchema::Key_Space_HOLD()
{
	//typeid(int).name()
	std::cout << "HOLD" << std::endl;
}

void TestControlSchema::Mouse_Movement()
{
	std::cout << "Cursor Position at (" << getInterface<IP_Interface>().mouseX << endl;
}

void TestControlSchema::ScrollMovement()
{
	std::cout << "Scroll X Value: " << getInterface<IP_Interface>().scrollX << endl;
	std::cout << "Scroll Y Value: " << getInterface<IP_Interface>().scrollY << endl;
}

void TestControlSchema::Mouse_Left_PRESS()
{
	//std::cout << "Left Button" << std::endl;
}

void TestControlSchema::Mouse_Left_HOLD()
{
	std::cout << "HOLD" << std::endl;

}

