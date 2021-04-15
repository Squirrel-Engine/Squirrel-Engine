#pragma once
#include <string>
#include "Actor.h"
#include "FurStore.h"

namespace Squirrel
{
	class Actor;
	class ActorComponent
	{
	private:
		Actor* parent;
	public:
		ActorComponent(){}
		virtual void BeginPlay() = 0;
		virtual void Update() = 0;
		virtual void setup() = 0;

		Uniforms* uniform;
	public:
		template<typename T>
		inline T getComponent(std::string name) { return dynamic_cast<T>(parent->componentList.at(name)); }
		inline Actor* getParent() { return parent; }
		inline void setParent(Squirrel::Actor* _parent) { this->parent = _parent; }
	};
}

