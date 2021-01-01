#pragma once
#include <vector>
#include "ActorComponent.h"
#include "TransformComponent.h"


namespace Squirrel
{
	class Actor
	{
		virtual void BeginPlay();
		virtual void Update();

		Actor();

		TransformComponent* transformComponent;

		std::vector<ActorComponent*> componentList;

		void bindComponent(ActorComponent component);
	};


}
