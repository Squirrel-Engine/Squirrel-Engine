#pragma once
#include <string>

#include "Actor.h"
#include "IStore.h"

namespace Squirrel
{
	class LevelStore
	{
		
	public:
		LevelStore();

		std::vector<Actor*> actors;
		std::vector<Actor*> cameras;
		//camera
		//lights
		std::string name;


		void spawnNewActor(Actor* actor);
		void spawnNewCamera(Actor* camera);

		Actor* getActor(int index);
		void setupStore(std::string _name, std::vector<Actor*> initialActorVector);
	};
}
