#pragma once
#include <string>
#include "Actor.h"
#include "IStore.h"

namespace Squirrel
{
	enum class EActorType {
		ACTOR,
		CAMERA,
		LIGHT
	};

	class LevelStore
	{
		
	public:
		LevelStore();

		std::vector<Actor*> actors;
		std::vector<Actor*> lights;
		Actor* mainCamera;
		
		std::string name;

		void spawnNewActor(EActorType type, Actor* actor);

		Actor* getActor(EActorType type, int row);

		void setupStore(std::string _name, std::vector<Actor*> initialActorVector);
	};

}
