#include "Actor.h"


namespace Squirrel
{
	Actor::Actor()
	{
	}

	void Actor::bindComponent(ActorComponent* component)
	{
		componentList.push_back(component);
	}

}

