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
	if (getInterface<RD_Interface>().frameCounter == 1)
	{
		actor->BeginPlay();
		actor->Update();
		for (auto& component : actor->componentList)
		{
			component.second->setup();
			component.second->BeginPlay();
			component.second->Update();
		}

	}
	else {
		actor->Update();
		for (auto& component : actor->componentList)
		{
			component.second->Update();
		}
	}

}
