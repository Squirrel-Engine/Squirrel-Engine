#pragma once
#include <vector>
#include "ActorComponent.h"



namespace Squirrel
{
	class Actor
	{
		virtual void BeginPlay();
		virtual void Update();

		Actor();

		std::vector<ActorComponent*> componentList;

		void bindComponent(ActorComponent* component);
	};


}
