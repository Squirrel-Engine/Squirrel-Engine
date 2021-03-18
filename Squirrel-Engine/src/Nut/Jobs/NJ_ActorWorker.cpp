#include "NJ_ActorWorker.h"

Squirrel::NJ_ActorWorker::NJ_ActorWorker(Actor* _actor) : actor(_actor)
{

}

void Squirrel::NJ_ActorWorker::mount()
{
}

void Squirrel::NJ_ActorWorker::unmount()
{
}

void Squirrel::NJ_ActorWorker::run()
{
	actor->Update();
	for (auto& component : actor->componentList)
	{
		component.second->Update();
	}
}
