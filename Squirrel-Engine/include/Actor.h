#pragma once
#include <unordered_map>
#include <typeinfo>
#include <iostream>
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

	std::unordered_map<const char*, ActorComponent*> componentList;
public:
	template <class T>
	inline void insertComponent(T component)
	{
		componentList.insert(std::make_pair(typeid(component).name(), component));
	}
};
