#include "Components/AIComponent.h"




AIComponent::AIComponent()
{
	actionNode = new WalkToDoorAction();
}

void AIComponent::BeginPlay()
{

}

void AIComponent::Update()
{
	actionNode = behaviorTree->executeTree();
	// Initialization 
	if(actionNode->isFreshStart == true)
	{
		actionNode->onInitialize();
		actionNode->isFreshStart = false;
		actionNode->actionStatus = EActionStatus::RUNNING;
	}

	// Action
	if(actionNode->actionStatus == EActionStatus::RUNNING)
	{
		actionNode->onAction();
	}

	// Decision 
	if(actionNode->actionStatus == EActionStatus::FAILED)
	{
		actionNode->onTerminate();
	}
	else if (actionNode->actionStatus == EActionStatus::SUCCEED)
	{
		//trigger event
	}
}


void AIComponent::setup()
{
	
}
