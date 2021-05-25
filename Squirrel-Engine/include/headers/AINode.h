#pragma once
#include <vector>
#include "EAINode.h"
class AINode
{
public:
	std::vector<AINode*> nodes;
	AINode* parent;
	EAINode nodeType;

	int counter = -1;
};
