#include "BehaviorTree.h"

BehaviorTree::BehaviorTree()
{
	rootNode = new AINode();
}

void BehaviorTree::insertNode(AINode* node, std::string nodeName, EAINode nodeType)
{
	rootNode->nodes.push_back(nullptr);

	if(rootNode->nodes.at(0) == nullptr)
	{
		for (int i = 0; i < 10; i++) {
			node->nodes.push_back(nullptr);
		}
		rootNodeName = nodeName;
		rootNode->nodes.at(0) = node;
		node->nodeType = nodeType;
		nodeList.insert(std::pair<std::string, AINode*>(nodeName, node));
	}
	else
	{
		node->nodes.push_back(nullptr);
		node->nodeType = nodeType;
		nodeList.insert(std::make_pair(nodeName, node));
	}
}

void BehaviorTree::linkNode(std::string nodeOne, std::string nodeTwo)
{
	int x = 0;

	while (1) {

		if (nodeList[nodeOne]->nodes.at(x) == nullptr) {
			if (nodeOne == rootNodeName) {
				nodeList[nodeOne]->nodes.at(x) = nodeList[nodeTwo];
				nodeList[nodeTwo]->parent = nodeList[nodeOne];
				rootNode->nodes.at(x) = nodeList[nodeOne];
				break;
			}
			else {
				nodeList[nodeOne]->nodes.at(x) = nodeList[nodeTwo];
				nodeList[nodeTwo]->parent = nodeList[nodeOne];
			}
			break;
		}
		else {
			x++;
			continue;
		}	
	}	
}

ActionNode* BehaviorTree::executeTree()
{
	AINode* iter;
	int i = 0;
	iter = nodeList[rootNodeName];

	while(1) {

		switch (iter->nodeType)
		{
		case EAINode::SEQUENCE:
			break;
		case EAINode::SELECTION:
			this->counter++;
			if (iter->nodes.at(this->counter) != nullptr) {
				iter = iter->nodes.at(this->counter);
			}
			else {
				this->counter--;
				iter = iter->nodes.at(this->counter);
			}
		break;
		case EAINode::DECORATOR:
			if (static_cast<DecoratorNode*>(iter)->decoratorCase() == true)
			{
				iter = iter->nodes.at(0);
				this->counter = -1;
			}
			else
			{
				iter = iter->parent;
			}
		break;
		case EAINode::ACTION:
			this->counter = -1;
			return static_cast<ActionNode*>(iter);

		break;
		default:
			break;
		}
	}
}

