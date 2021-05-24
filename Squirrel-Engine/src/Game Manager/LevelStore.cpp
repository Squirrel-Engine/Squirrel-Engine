#include "LevelStore.h"

std::unordered_map<std::string, Actor*> LevelStore::m_Actors;
std::unordered_map<std::string, Actor*> LevelStore::m_Lights;
std::unordered_map<std::string, Actor*> LevelStore::m_Cameras;
std::string LevelStore::m_MainCamera = "MainCamera";

LevelStore::LevelStore()
{
}

void LevelStore::spawnNewActor(EActorType type, Actor* actor, std::string actorName)
{
	switch (type)
	{
	case EActorType::ACTOR:
		m_Actors[actorName] = actor;

		break;
	case EActorType::CAMERA:
		m_Cameras[actorName] = actor;
		m_MainCamera = actorName;

		break;
	case EActorType::LIGHT:
		m_Lights[actorName] = actor;
		break;
	default:
		break;
	}
}

Actor* LevelStore::getActor(EActorType type, std::string actorName)
{
	switch (type)
	{
	case EActorType::ACTOR:
		if(m_Actors.find(actorName) != m_Actors.end())
		{
			return m_Actors[actorName];
		}

	case EActorType::CAMERA:
		if (m_Cameras.find(actorName) != m_Cameras.end())
		{
			return m_Cameras[actorName];
			
		}
	case EActorType::LIGHT:
		if (m_Lights.find(actorName) != m_Lights.end())
		{
			return m_Lights[actorName];
		}
	}

	std::cout << "Actor Not Found!" << std::endl;
}

std::unordered_map<std::string, Actor*> LevelStore::getAllActors(EActorType type)
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
