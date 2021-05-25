#pragma once
#include "DecoratorNode.h"
#include "Blackboard.h"
#include <iostream>
class SampleDecorator : public DecoratorNode
{
public:
	SampleDecorator();
	bool decoratorCase() override;
};


