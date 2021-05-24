#pragma once
#include "NJob.h"
#include "DynamicLightManager.h"
#include "InterfaceFactory.h"

class NJ_InitializeRender final : public NJob
{
public:
	NJ_InitializeRender();
	void mount() override;
	void unmount() override;
	void run() override;
};
