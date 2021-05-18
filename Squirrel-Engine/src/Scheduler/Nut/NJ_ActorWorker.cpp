#include "NJ_ActorWorker.h"


NJ_ActorWorker::NJ_ActorWorker(Actor* _actor) : actor(_actor)
{
}

void NJ_ActorWorker::mount()
{
}

void NJ_ActorWorker::unmount()
{
}

void NJ_ActorWorker::run()
{
	actor->Update();
	for (auto& component : actor->componentList)
	{
		component.second->Update();
	}
}
