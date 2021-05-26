#pragma once
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
	void bindComponent(T* component);

	template <typename T>
	T* getComponent();

	template <typename T>
	void insertComponent(T component);
};

template <class T>
void Actor::bindComponent(T* component)
{
	component->setParent(this);
	insertComponent(component);
}

template <typename T>
T* Actor::getComponent() 
{
	return dynamic_cast<T*>(componentList.at(typeid(T*).name()));
}

template <typename T>
void Actor::insertComponent(T component) 
{
	componentList.insert(std::make_pair(typeid(component).name(), component));
}