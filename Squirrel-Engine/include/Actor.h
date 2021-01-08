#pragma once
#include <vector>
#include "ActorComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"


namespace Squirrel
{
	class Actor
	{
		virtual void BeginPlay();
		virtual void Update();

		Actor();

		TransformComponent* transformComponent;
		RenderComponent* renderComponent;
		std::vector<ActorComponent*> componentList;

		void bindComponent(ActorComponent component);
	};


}
