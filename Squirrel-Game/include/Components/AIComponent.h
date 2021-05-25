#pragma once
#include "Macros.h"
#include "ActorComponent.h"
#include "SkeletonAI/WalkToDoorAction.h"
#include "ActionNode.h"
#include "BehaviorTree.h"


SR_COMPONENT()

class AIComponent : public ActorComponent
{
public:
	AIComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;


	SR_VAR_START()

	SR_VAR_END()
	BehaviorTree* behaviorTree;
	Blackboard* blackBoard;
	ActionNode* actionNode;

};

SR_COMPONENT()