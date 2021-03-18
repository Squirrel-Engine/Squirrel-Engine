#pragma once
#include "Actor.h"
#include "NJob.h"

namespace Squirrel
{
	class NJ_ActorWorker final : public NJob
	{
	public:
		Actor* actor;
		NJ_ActorWorker(Actor* _actor);
		void mount() override;
		void unmount() override;
		void run() override;
	};
}
