#pragma once
#include <map>
#include <string>

#include "SequenceNode.h"
#include "DecoratorNode.h"
#include "ActionNode.h"
#include "EAINode.h"


struct NodePair
{
	AINode* node;
	EAINode nodeType;
};

class RootNode
{
public:
	AINode* next = nullptr;
};

class BehaviorTree
{
public:
	RootNode* rootNode;
	
	BehaviorTree();
	void insertNode(AINode* node, std::string nodeName, EAINode nodeType);
	void linkNode(std::string nodeOne, std::string nodeTwo);
	ActionNode* executeTree();

	std::map<std::string, AINode*> nodeList;
	
};