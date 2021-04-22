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


