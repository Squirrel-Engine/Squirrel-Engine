#pragma once
#include "NJob.h"
namespace Squirrel
{
	class NJ_InitializeRender final : public NJob
	{
	public:
		NJ_InitializeRender();
		void mount() override;
		void unmount() override;
		void run() override;
	};
}
