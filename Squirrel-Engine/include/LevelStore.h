#pragma once
#include <string>
#include "Actor.h"
#include <map>

enum class EActorType
{
	ACTOR,
	CAMERA,
	LIGHT
};

class LevelStore
{
public:
	LevelStore();

	template <class T>
	static  T* createActor(EActorType type, std::string actorName);
	
	static void spawnNewActor(EActorType type, Actor* actor, std::string actorName);
	static Actor* getActor(EActorType type, std::string actorName);
	static std::unordered_map<std::string, Actor*> getAllActors(EActorType type);
public:
	static std::string m_MainCamera;
private:
	static std::unordered_map<std::string, Actor*> m_Actors;
	static std::unordered_map<std::string, Actor*> m_Lights;
	static std::unordered_map<std::string, Actor*> m_Cameras;
};

template <class T>
T* LevelStore::createActor(EActorType type, std::string actorName)
{
	T* actor = new T();
	spawnNewActor(type, actor, actorName);
	return actor;
}