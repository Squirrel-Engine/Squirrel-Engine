#include "BehaviorTree.h"
#include "pch.h"

BehaviorTree::BehaviorTree()
{
	rootNode = new AINode();
}

void BehaviorTree::insertNode(AINode* node, std::string nodeName, EAINode nodeType)
{
	if (nodeType == EAINode::SEQUENCE) {
		sequenceList.push_back(node);
	}

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
		for (int i = 0; i < 10; i++) {
			node->nodes.push_back(nullptr);
		}
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

void BehaviorTree::resetSequenceList()
{
	for (int i = 0; i < sequenceList.size(); i++) {
		sequenceList[i]->counter = -1;
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
			iter->counter++;

			if (iter->nodes.at(iter->counter) != nullptr) {
				if (iter->nodes.at(iter->counter)->nodeType == EAINode::SEQUENCE) {
					
					iter = iter->nodes.at(iter->counter);
					iter->parent->counter--;
					
				}
				else {
					iter = iter->nodes.at(iter->counter);
					iter->parent->counter++;

					if (iter->parent->nodes.at(iter->parent->counter) == nullptr) {

						iter->parent->counter--;
						

						for (const auto& item : sequenceList)
						{
							item->counter++;
						}
			
						if (iter->parent->parent == nullptr) {
							resetSequenceList();
						}
						else if (iter->parent->parent->nodes.at(iter->parent->parent->counter + 1) == nullptr) {
							resetSequenceList();
						}
					}
					else {
						iter->parent->counter--;
					}
				}

			}

			break;
		case EAINode::SELECTION:
			this->counter++;

			if (iter->nodes.at(this->counter) != nullptr) {
				iter = iter->nodes.at(this->counter);
			}
			else {
				break;
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

