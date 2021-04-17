#pragma once
#include "NJob.h"
#include "InterfaceFactory.h"
#include "NJ_InitializeFrame.h"

class NJ_InitializeRender final : public NJob
{
public:
	NJ_InitializeRender();
	void mount() override;
	void unmount() override;
	void run() override;
};

