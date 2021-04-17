#include "LevelStore.h"

LevelStore::LevelStore()
{
}

void LevelStore::spawnNewActor(EActorType type, Actor* actor)
{
	switch (type)
	{
	case EActorType::ACTOR:
		actors.push_back(actor);
		break;
	case EActorType::CAMERA:
		mainCamera = actor;
		break;
	case EActorType::LIGHT:
		lights.push_back(actor);
		break;
	default:
		break;
	}
}

Actor* LevelStore::getActor(EActorType type, int row)
{
	switch (type)
	{
	case EActorType::ACTOR:
		return actors[row];
	case EActorType::CAMERA:
		return mainCamera;
	case EActorType::LIGHT:
		return lights[row];
	}
}

void LevelStore::setupStore(std::string _name, std::vector<Actor*> initialActorVector)
{
	name = name;
	actors = initialActorVector;
}
