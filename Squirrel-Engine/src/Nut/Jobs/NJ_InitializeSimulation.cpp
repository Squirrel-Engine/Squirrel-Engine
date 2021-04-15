#include "NJ_InitializeSimulation.h"

#include "NJ_ActorWorker.h"
namespace Squirrel {
	NJ_InitializeSimulation::NJ_InitializeSimulation()
	{
	}

	void NJ_InitializeSimulation::mount()
	{
	}

	void NJ_InitializeSimulation::unmount()
	{
	}

	void NJ_InitializeSimulation::run()
	{
		for (int i = 0; i < InterfaceFactory::getInstance().getGMInterface().levelStore->actors.size(); i++)
		{
			InterfaceFactory::getInstance().getMTInterface().submitJob(*new NJ_ActorWorker(InterfaceFactory::getInstance().getGMInterface().levelStore->actors.at(i)), EQueueOrder::LOW_ORDER);
		}
		//Camera Job
		InterfaceFactory::getInstance().getMTInterface().submitJob(*new NJ_ActorWorker(InterfaceFactory::getInstance().getGMInterface().levelStore->mainCamera), EQueueOrder::LOW_ORDER);
	}

}
