#pragma once
#include <map>
#include <string>

#include "SequenceNode.h"
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
	void resetSequenceList();
	ActionNode* executeTree();

	int counter = -1;
	
	std::vector<SequenceNode*> sequenceList;

	std::map<std::string, AINode*> nodeList;

	std::string rootNodeName;
	
};