#include "LevelStore.h"

namespace Squirrel
{
	LevelStore::LevelStore()
	{
	}

	void LevelStore::spawnNewActor(Actor* actor)
	{
		actors.insert(actors.begin(), actor);
	}

	Actor* LevelStore::getActor(int row)
	{
		return actors[row];
	}

	void LevelStore::setupStore(std::string _name, std::vector<Actor*> initialActorVector)
	{
		name = name;
		actors = initialActorVector;
	}


}
