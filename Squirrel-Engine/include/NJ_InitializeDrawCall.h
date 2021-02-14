#pragma once
#include "NJob.h"
namespace Squirrel
{
	class NJ_InitializeDrawCall final : public NJob
	{
	public:
		NJ_InitializeDrawCall();
		void mount() override;
		void unmount() override;
		void run() override;
	};
}
