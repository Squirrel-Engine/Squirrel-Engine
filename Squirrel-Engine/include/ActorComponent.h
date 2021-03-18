#pragma once
#include <string>

#include "Actor.h"

namespace Squirrel
{
	class Actor;
	class ActorComponent
	{
	public:
		ActorComponent(){}
		virtual void BeginPlay() = 0;
		virtual void Update() = 0;
		Actor* parent;
	public:
		template<typename T>
		inline T getComponent(std::string name) { return dynamic_cast<T>(parent->componentList.at(name)); }
		
		inline void setParent(Squirrel::Actor* _parent) { this->parent = _parent; }
	};
}

