#pragma once
#include "../../Squirrel-Engine/include/ActionNode.h"
#include "../../Squirrel-Engine/include/Blackboard.h"
#include <iostream>
class WalkToDoorAction : public ActionNode
{
public:
	WalkToDoorAction();
	void onInitialize() override;
	void onAction() override;
	void onTerminate() override;
	int test = 0;
};

class WalkToDoorAction2 : public ActionNode
{
public:
	WalkToDoorAction2();
	void onInitialize() override;
	void onAction() override;
	void onTerminate() override;
	int test = 0;
};