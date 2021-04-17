#pragma once
#include "NJob.h"

#include "InterfaceFactory.h"

class NJ_InitializeSimulation final : public NJob
{
public:
	NJ_InitializeSimulation();
	void mount() override;
	void unmount() override;
	void run() override;
};

