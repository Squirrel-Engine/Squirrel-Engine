#pragma once

namespace Squirrel
{
	class ActorComponent
	{
	public:
		virtual void BeginPlay() = 0;
		virtual void Update() = 0;
	};
}

