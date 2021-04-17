#pragma once
#include "NJob.h"

class NJ_InitializeDrawCall final : public NJob
{
public:
	NJ_InitializeDrawCall();
	void mount() override;
	void unmount() override;
	void run() override;
};

