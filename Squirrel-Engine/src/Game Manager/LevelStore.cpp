#include "LevelStore.h"

std::vector<Actor*> LevelStore::m_Actors;
std::vector<Actor*> LevelStore::m_Lights;
std::vector<Actor*> LevelStore::m_Cameras;
int LevelStore::m_MainCamera = 0;

LevelStore::LevelStore()
{
}

void LevelStore::spawnNewActor(EActorType type, Actor* actor)
{
	switch (type)
	{
	case EActorType::ACTOR:
		m_Actors.push_back(actor);
		break;
	case EActorType::CAMERA:
		m_Cameras.push_back(actor);
		break;
	case EActorType::LIGHT:
		m_Lights.push_back(actor);
		break;
	default:
		break;
	}
}

Actor* LevelStore::getActor(EActorType type, int index)
{
	switch (type)
	{
	case EActorType::ACTOR:
		return m_Actors[index];
	case EActorType::CAMERA:
		return m_Cameras[index];
	case EActorType::LIGHT:
		return m_Lights[index];
	}
}

std::vector<Actor*> LevelStore::getAllActors(EActorType type)
{
	switch (type)
	{
	case EActorType::ACTOR:
		return m_Actors;
	case EActorType::LIGHT:
		return m_Lights;
	case EActorType::CAMERA:
		return m_Cameras;
	}
}
