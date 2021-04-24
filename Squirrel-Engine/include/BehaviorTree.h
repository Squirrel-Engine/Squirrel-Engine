#pragma once
#include <map>
#include <string>

#include "SelectionNode.h"
#include "DecoratorNode.h"
#include "ActionNode.h"
#include "EAINode.h"
#include <iostream>


class RootNode
{
public:
	AINode* next = nullptr;
};

class BehaviorTree
{
public:
	AINode* rootNode;
	
	BehaviorTree();
	void insertNode(AINode* node, std::string nodeName, EAINode nodeType);
	void linkNode(std::string nodeOne, std::string nodeTwo);
	ActionNode* executeTree();

	int counter = -1;

	std::map<std::string, AINode*> nodeList;

	std::string rootNodeName;
	
};