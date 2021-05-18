#pragma once
#include "NJ_InitializeFrame.h"

#include "InterfaceFactory.h"
#include "NJ_InitializeDrawCall.h"
#include "NJ_InitializeRender.h"
#include "NJ_InitializeSimulation.h"
#include "NJ_Input.h"


NJ_InitializeFrame::NJ_InitializeFrame()
{
}

void NJ_InitializeFrame::mount()
{
}

void NJ_InitializeFrame::unmount()
{
}

void NJ_InitializeFrame::run()
{
	//Set the timer
	Timer::update();
	std::cout << Timer::getMiliSeconds() << std::endl;

	//Push all high order jobs to initialize a frame
	getInterface<MT_Interface>().submitJob(*new NJ_Input(), EQueueOrder::HIGH_ORDER);
	getInterface<MT_Interface>().submitJob(*new NJ_InitializeSimulation(), EQueueOrder::HIGH_ORDER);
	getInterface<MT_Interface>().submitJob(*new NJ_InitializeRender(), EQueueOrder::HIGH_ORDER);
}
