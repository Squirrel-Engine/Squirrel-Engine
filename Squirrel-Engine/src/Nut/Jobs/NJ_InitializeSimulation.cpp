#include "NJ_InitializeSimulation.h"

#include "InterfaceFactory.h"

Squirrel::NJ_InitializeSimulation::NJ_InitializeSimulation()
{
	jobStage = EJobStage::SYSTEM;
}

void Squirrel::NJ_InitializeSimulation::mount()
{
}

void Squirrel::NJ_InitializeSimulation::unmount()
{
}

void Squirrel::NJ_InitializeSimulation::run()
{
	std::cout << "Simulate Game" << std::endl; 
}
