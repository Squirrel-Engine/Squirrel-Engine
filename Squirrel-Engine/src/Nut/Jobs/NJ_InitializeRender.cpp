#include "NJ_InitializeRender.h"


#include <iostream>
#include <ostream>

Squirrel::NJ_InitializeRender::NJ_InitializeRender()
{
	jobStage = EJobStage::SYSTEM;
}

void Squirrel::NJ_InitializeRender::mount()
{
}

void Squirrel::NJ_InitializeRender::unmount()
{
}

void Squirrel::NJ_InitializeRender::run()
{
	std::cout << "Render Game" << std::endl;
}
