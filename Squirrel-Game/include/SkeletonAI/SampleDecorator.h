#pragma once
#include "../../Squirrel-Engine/include/DecoratorNode.h"
#include "../../Squirrel-Engine/include/Blackboard.h"
#include <iostream>
class SampleDecorator : public DecoratorNode
{
public:
	SampleDecorator();
	bool decoratorCase() override;
};


