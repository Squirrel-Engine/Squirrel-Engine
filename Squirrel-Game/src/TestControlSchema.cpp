#include "ControlSchema/TestControlSchema.h"


void TestControlSchema::Key_SPACE() {
	std::cout << "Hello World" << std::endl;
}

void TestControlSchema::Mouse_Movement()
{
	cout << "Cursor Position at (" << Squirrel::InterfaceFactory::getInstance().getIPInterface().mouseX << endl;
}

