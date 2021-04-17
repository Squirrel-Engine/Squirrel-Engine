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
	std::cout << "Cursor Position at (" << Squirrel::InterfaceFactory::getInstance().getIPInterface().mouseX << endl;
}

void TestControlSchema::ScrollMovement()
{
	std::cout << "Scroll X Value: " << Squirrel::InterfaceFactory::getInstance().getIPInterface().scrollX << endl;
	std::cout << "Scroll Y Value: " << Squirrel::InterfaceFactory::getInstance().getIPInterface().scrollY << endl;
}

void TestControlSchema::Mouse_Left_PRESS()
{
	//std::cout << "Left Button" << std::endl;
}

void TestControlSchema::Mouse_Left_HOLD()
{
	std::cout << "HOLD" << std::endl;

}

