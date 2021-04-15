#pragma once
#include "../../Squirrel-Engine/include/ControlSchema.h"
#include <iostream>
class TestControlSchema: public Squirrel::ControlSchematic
{
public:
	TestControlSchema() {};
	void Key_SPACE() override;
};

