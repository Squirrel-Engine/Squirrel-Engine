#include "SkeletonAI/WalkToDoorAction.h"

WalkToDoorAction::WalkToDoorAction()
{
}

void WalkToDoorAction::onInitialize()
{
	std::cout << "The third action is going to start." << std::endl;
}

void WalkToDoorAction::onAction()
{
	test = *blackBoard->getIntVariable("test");

	std::cout << "The value of test: " << test << std::endl;

	if (test == 1000) {
		test = 2000;
		std::cout << "The value of test: " << test << std::endl;
		actionStatus = EActionStatus::FAILED;
	}

}

void WalkToDoorAction::onTerminate()
{
	std::cout << "3rd Action Terminated" << std::endl;	
}


//----------------------------------------//


WalkToDoorAction2::WalkToDoorAction2()
{
}

void WalkToDoorAction2::onInitialize()
{
	std::cout << "The first action is going to start." << std::endl;
}

void WalkToDoorAction2::onAction()
{
	Sleep(1000);

	if (counter >= 1)
	{
		std::cout << "Timer: " << counter << std::endl;
		counter--;
		actionStatus = EActionStatus::RUNNING;
	}
	else {
		std::cout << "First action succeed" << std::endl;
		actionStatus = EActionStatus::SUCCEED;
	}
}

void WalkToDoorAction2::onTerminate()
{
}


//----------------------------------------//


WalkToDoorAction3::WalkToDoorAction3()
{

}

void WalkToDoorAction3::onInitialize()
{
	std::cout << "The second action is going to start." << std::endl;
}

void WalkToDoorAction3::onAction()
{
	Sleep(1000);

	if (counter >= 1)
	{
		std::cout << "Timer: " << counter << std::endl;
		counter--;
		actionStatus = EActionStatus::RUNNING;
	}
	else {
		std::cout << "Second action succeed" << std::endl;
		actionStatus = EActionStatus::SUCCEED;
	}
}

void WalkToDoorAction3::onTerminate()
{
}

