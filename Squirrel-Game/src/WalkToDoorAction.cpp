#include "SkeletonAI/WalkToDoorAction.h"



WalkToDoorAction::WalkToDoorAction()
{
	//blackBoard = _blackBoard;
}




void WalkToDoorAction::onInitialize()
{
	std::cout << "I will start walk" << std::endl;
}

void WalkToDoorAction::onAction()
{
	std::cout << "Walking " << test << std::endl;
	test++;
	if (test == 500)
	{
		actionStatus = EActionStatus::SUCCEED;
	}
		if (test > 500)
	{
		actionStatus = EActionStatus::FAILED;

	}
}

void WalkToDoorAction::onTerminate()
{
	std::cout << "Action Terminated" << std::endl;
}

WalkToDoorAction2::WalkToDoorAction2()
{
}

void WalkToDoorAction2::onInitialize()
{
	std::cout << "I will start walk2" << std::endl;
}

void WalkToDoorAction2::onAction()
{
	std::cout << "Walking2 " << test << std::endl;
	test++;
	if (test == 500)
	{
		actionStatus = EActionStatus::SUCCEED;
	}
	if (test > 500)
	{
		actionStatus = EActionStatus::FAILED;

	}
}

void WalkToDoorAction2::onTerminate()
{
	std::cout << "Action Terminated (Is it?)" << std::endl;
}
