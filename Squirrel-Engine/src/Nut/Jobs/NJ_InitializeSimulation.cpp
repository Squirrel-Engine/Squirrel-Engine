#include "NJ_InitializeSimulation.h"

#include "InterfaceFactory.h"
#include "NJ_ActorWorker.h"

Squirrel::NJ_InitializeSimulation::NJ_InitializeSimulation()
{
}

void Squirrel::NJ_InitializeSimulation::mount()
{
}

void Squirrel::NJ_InitializeSimulation::unmount()
{
}

void Squirrel::NJ_InitializeSimulation::run()
{
	//Actors
	for (auto& actor : InterfaceFactory::getInstance().getGMInterface().levelStore->actors) {
		InterfaceFactory::getInstance().getMTInterface().submitJob(*new NJ_ActorWorker(actor), EQueueOrder::LOW_ORDER);
	}
	//Lights
	for (auto& light : InterfaceFactory::getInstance().getGMInterface().levelStore->lights) {
		InterfaceFactory::getInstance().getMTInterface().submitJob(*new NJ_ActorWorker(light), EQueueOrder::LOW_ORDER);
	}
	//Camera
	InterfaceFactory::getInstance().getMTInterface().submitJob(*new NJ_ActorWorker(InterfaceFactory::getInstance().getGMInterface().levelStore->mainCamera), EQueueOrder::LOW_ORDER);
}
