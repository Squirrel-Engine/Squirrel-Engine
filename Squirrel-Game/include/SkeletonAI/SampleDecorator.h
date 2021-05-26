#pragma once
#include "DecoratorNode.h"
#include "Blackboard.h"

class SampleDecorator : public DecoratorNode
{
public:
	SampleDecorator();
	bool decoratorCase() override;
};


