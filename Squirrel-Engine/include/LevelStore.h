#pragma once
#include <string>
#include "Actor.h"
#include "IStore.h"

enum class EActorType {
	ACTOR,
	CAMERA,
	LIGHT
};

class LevelStore
{

public:
	LevelStore();

	std::vector<Squirrel::Actor*> actors;
	std::vector<Squirrel::Actor*> lights;
	Squirrel::Actor* mainCamera;

	std::string name;

	void spawnNewActor(EActorType type, Squirrel::Actor* actor);

	Squirrel::Actor* getActor(EActorType type, int row);

	void setupStore(std::string _name, std::vector<Squirrel::Actor*> initialActorVector);
};
