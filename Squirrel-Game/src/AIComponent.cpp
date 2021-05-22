#include "Components/AIComponent.h"




AIComponent::AIComponent()
{
	behaviorTree = new BehaviorTree();
}

void AIComponent::BeginPlay()
{
	actionNode = behaviorTree->executeTree();
	actionNode->setBlackBoard(blackBoard);
}

void AIComponent::Update()
{
	if (actionNode == nullptr) {

	}
	else {
		if (blackBoard->isBlackboardUpdated()) {
			actionNode = behaviorTree->executeTree();
		}

		actionNode->setBlackBoard(blackBoard);

		// Initialization 
		if (actionNode->isFreshStart == true)
		{
			actionNode->onInitialize();
			actionNode->isFreshStart = false;
			actionNode->actionStatus = EActionStatus::RUNNING;
		}

		// Action
		if (actionNode->actionStatus == EActionStatus::RUNNING)
		{
			actionNode->onAction();
		}

		// Decision 
		if (actionNode->actionStatus == EActionStatus::FAILED)
		{
			actionNode->onTerminate();
			actionNode = nullptr;
			behaviorTree->resetSequenceList();
		}
		else if (actionNode->actionStatus == EActionStatus::SUCCEED)
		{
			actionNode = behaviorTree->executeTree();
			//trigger event
		}
	}

}


void AIComponent::setup()
{
	
}
