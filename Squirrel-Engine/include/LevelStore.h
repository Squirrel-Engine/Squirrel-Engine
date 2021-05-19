#pragma once
#include <string>
#include "Actor.h"

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
	static  T* createActor(EActorType type);
	
	static void spawnNewActor(EActorType type, Actor* actor);
	static Actor* getActor(EActorType type, int row);
	static std::vector<Actor*> getAllActors(EActorType type);
public:
	static int m_MainCamera;
private:
	static std::vector<Actor*> m_Actors;
	static std::vector<Actor*> m_Lights;
	static std::vector<Actor*> m_Cameras;
};

template <class T>
T* LevelStore::createActor(EActorType type)
{
	T* actor = new T();
	spawnNewActor(type, actor);
	return actor;
}