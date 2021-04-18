#include "NJ_InitializeSimulation.h"
#include "NJ_ActorWorker.h"

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
	//Actors
	for (auto& actor : getInterface<GM_Interface>().levelStore->actors)
	{
		getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(actor), EQueueOrder::LOW_ORDER);
	}
	//Lights
	for (auto& light : getInterface<GM_Interface>().levelStore->lights)
	{
		getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(light), EQueueOrder::LOW_ORDER);
	}
	//Camera
	getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(getInterface<GM_Interface>().levelStore->mainCamera),
	                                       EQueueOrder::LOW_ORDER);
}
