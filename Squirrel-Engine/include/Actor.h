#pragma once
#include <unordered_map>
#include <vector>
#include "ActorComponent.h"

class ActorComponent;

class Actor
{
public:
	virtual void BeginPlay() = 0;
	virtual void Update() = 0;

	Actor()
	{
	};

	std::unordered_map<std::string, ActorComponent*> componentList;
public:
	inline void Actor::insertComponent(std::string name, ActorComponent* component)
	{
		componentList.insert(std::make_pair(name, component));
	}
};
