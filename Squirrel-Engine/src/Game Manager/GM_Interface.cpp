#include "GM_Interface.h"

GM_Interface::GM_Interface()
{

}

void GM_Interface::configureComponents()
{
	for (auto& actor : LevelStore::getAllActors(EActorType::ACTOR)) {
		for (auto& component : actor.second->componentList)
		{
			component.second->setup();
		}
	}
	for (auto& lights : LevelStore::getAllActors(EActorType::LIGHT)) {
		for (auto& component : lights.second->componentList)
		{
			component.second->setup();
		}
	}
	for (auto& component : LevelStore::getActor(EActorType::CAMERA, LevelStore::m_MainCamera)->componentList)
	{
		component.second->setup();
	}
}
