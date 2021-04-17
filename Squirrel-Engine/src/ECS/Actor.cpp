#include "Actor.h"

void Actor::insertComponent(std::string name, ActorComponent* component)
{
	componentList.insert(std::make_pair(name, component));
}
