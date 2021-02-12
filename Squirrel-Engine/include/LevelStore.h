#pragma once
#include <string>

#include "Actor.h"
#include "IStore.h"

namespace Squirrel
{
	class LevelStore : IStore
	{
		
	public:
		LevelStore();

		std::vector<Actor*> actors;
		std::string name;


		void spawnNewActor(Actor* actor);
		Actor* getActor(int row);
		void setupStore(std::string _name, std::vector<Actor*> initialActorVector);
	};
}
