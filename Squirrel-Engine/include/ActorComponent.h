#pragma once
#include <string>
#include "Actor.h"
#include "UniformDesc.h"
#include "FurStore.h"

class Actor;

class ActorComponent
{
private:
	Actor* parent;
public:
	ActorComponent()
	{
	};

	virtual void BeginPlay() = 0;
	virtual void Update() = 0;
	virtual void setup() = 0;

	Uniforms* uniform;
public:
	template <typename T>
	T getComponent(std::string name) { return dynamic_cast<T>(parent->componentList.at(name)); }

	Actor* getParent() { return parent; }
	void setParent(Actor* _parent) { this->parent = _parent; }
};
