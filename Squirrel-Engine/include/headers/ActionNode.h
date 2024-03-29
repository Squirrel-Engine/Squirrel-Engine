#pragma once
#include "AINode.h"
#include "Blackboard.h"
#include "EActionStatus.h"

class ActionNode : public AINode
{
public:
	ActionNode();
	virtual void onInitialize() = 0;
	virtual void onAction() = 0;
	virtual void onTerminate() = 0;
	void setBlackBoard(Blackboard* blackBoard) {
		this->blackBoard = blackBoard;
	}
	EActionStatus actionStatus;
	Blackboard* blackBoard;

	bool isFreshStart = true;
	
};