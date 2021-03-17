#pragma once
#include "NJ_InitializeFrame.h"

#include "InterfaceFactory.h"
#include "NJ_InitializeDrawCall.h"
#include "NJ_InitializeRender.h"
#include "NJ_InitializeSimulation.h"

namespace Squirrel
{
	NJ_InitializeFrame::NJ_InitializeFrame()
	{
		jobStage = EJobStage::SYSTEM;
		
	}

	void NJ_InitializeFrame::mount()
	{
	}

	void NJ_InitializeFrame::unmount()
	{
	}

	void NJ_InitializeFrame::run()
	{
		InterfaceFactory::getInstance().getMTInterface().submitJob(new NJ_InitializeSimulation());
		InterfaceFactory::getInstance().getMTInterface().submitJob(new NJ_InitializeDrawCall());
		InterfaceFactory::getInstance().getMTInterface().submitJob(new NJ_InitializeRender());
	}
}
