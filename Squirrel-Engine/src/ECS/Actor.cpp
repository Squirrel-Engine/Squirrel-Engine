#include "Actor.h"

namespace Squirrel
{
	void Actor::insertComponent(std::string name, ActorComponent* component)
	{
		componentList.insert(std::make_pair(name, component));
	}
}