#pragma once
#include "AINode.h"

class DecoratorNode : public AINode
{
public:
	virtual bool decoratorCase() = 0;
};
