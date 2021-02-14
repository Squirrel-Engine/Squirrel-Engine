#pragma once
#include "NJob.h"
namespace Squirrel
{
	class NJ_InitializeFrame final : public NJob
	{
	public:
		NJ_InitializeFrame();
		void mount() override;
		void unmount() override;
		void run() override;
	};
}
