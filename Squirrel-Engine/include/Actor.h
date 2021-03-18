#pragma once
#include <unordered_map>
#include <vector>
#include "ActorComponent.h"

namespace Squirrel
{
	class ActorComponent;
	class Actor
	{
	public:
		virtual void BeginPlay() = 0;
		virtual void Update() = 0;

		Actor(){};

		std::unordered_map<std::string ,ActorComponent*> componentList;

		void insertComponent(std::string name, ActorComponent* component);
	};


}
