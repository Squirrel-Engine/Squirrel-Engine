#include "NJ_InitializeDrawCall.h"

#include <iostream>

Squirrel::NJ_InitializeDrawCall::NJ_InitializeDrawCall()
{
	jobStage = EJobStage::SYSTEM;
}

void Squirrel::NJ_InitializeDrawCall::mount()
{
}

void Squirrel::NJ_InitializeDrawCall::unmount()
{
}

void Squirrel::NJ_InitializeDrawCall::run()
{
	std::cout << "Submit Draw Calls" << std::endl;
}
