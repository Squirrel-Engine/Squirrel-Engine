#pragma once
#include "EAINode.h"
#include "pch.h"

class AINode
{
public:
	std::vector<AINode*> nodes;
	AINode* parent;
	EAINode nodeType;

	int counter = -1;
};
