#pragma once
#include "Macros.h"
#include "../../Squirrel-Engine/include/ActorComponent.h"
#include "SkeletonAI/WalkToDoorAction.h"
#include "../../Squirrel-Engine/include/ActionNode.h"
#include "../../Squirrel-Engine/include/BehaviorTree.h"


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