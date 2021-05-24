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
	for (auto& actor : LevelStore::getAllActors(EActorType::ACTOR))
	{
		getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(actor.second), EQueueOrder::LOW_ORDER);
	}
	//Lights
	for (auto& light : LevelStore::getAllActors(EActorType::LIGHT))
	{
		getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(light.second), EQueueOrder::LOW_ORDER);
	}
	//Camera
	getInterface<MT_Interface>().submitJob(*new NJ_ActorWorker(LevelStore::getActor(EActorType::CAMERA, LevelStore::m_MainCamera)), EQueueOrder::LOW_ORDER);
}
