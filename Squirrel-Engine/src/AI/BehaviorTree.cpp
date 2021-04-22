#include "BehaviorTree.h"

BehaviorTree::BehaviorTree()
{
	rootNode = new RootNode();
}

void BehaviorTree::insertNode(AINode* node, std::string nodeName, EAINode nodeType)
{
	if(rootNode->next == nullptr)
	{
		rootNode->next = node;
		node->nodeType = nodeType;
		nodeList.insert(std::make_pair(nodeName, node));
	}
	else
	{
		node->nodeType = nodeType;
		nodeList.insert(std::make_pair(nodeName, node));
	}
}

void BehaviorTree::linkNode(std::string nodeOne, std::string nodeTwo)
{
	AINode* NodeOne = nodeList[nodeOne];
	AINode* NodeTwo = nodeList[nodeTwo];
	for (auto& node : NodeOne->nodes)
	{
		if(node == nullptr)
		{
			node = NodeTwo;
			NodeTwo->parent = node;
		}
	}
}

ActionNode* BehaviorTree::executeTree()
{
	AINode* iter;
	iter = rootNode->next;
	while(true)
	{
		for (AINode*& node : iter->nodes)
		{
			if(node->nodeType == EAINode::DECORATOR)
			{
				if(static_cast<DecoratorNode*>(node)->decoratorCase() == true)
				{
					iter = node->nodes[0];
				}
			}
			if (node->nodeType == EAINode::SEQUENCE)
			{
				static_cast<SequenceNode*>(node)->counter++;
				iter = node->nodes[0];
			}
			if (node->nodeType == EAINode::ACTION)
			{
 
			}
		}
	}
}

