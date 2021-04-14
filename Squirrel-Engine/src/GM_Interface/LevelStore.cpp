#include "LevelStore.h"

namespace Squirrel
{
	LevelStore::LevelStore()
	{
	}

	void LevelStore::spawnNewCamera(Actor* camera)
	{
		mainCamera = camera;
	}

	void LevelStore::spawnNewActor(Actor* actor)
	{
		actors.push_back(actor);
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
