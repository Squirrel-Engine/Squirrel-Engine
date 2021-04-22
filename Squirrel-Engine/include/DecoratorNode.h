#pragma once
#include "AINode.h"

class DecoratorNode : public AINode
{
public:
	DecoratorNode();
	virtual bool decoratorCase(){};
};
