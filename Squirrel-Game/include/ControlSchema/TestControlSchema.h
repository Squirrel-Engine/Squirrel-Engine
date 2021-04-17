#pragma once
#include "../../Squirrel-Engine/include/ControlSchema.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"
#include <iostream>
class TestControlSchema: public ControlSchematic
{
public:
	TestControlSchema() {};
	void Key_SPACE_RELEASE() override;
	void Key_Space_HOLD() override;
	void Mouse_Movement() override;
	void ScrollMovement() override;

	void Mouse_Left_PRESS() override;
	void Mouse_Left_HOLD() override;
};

