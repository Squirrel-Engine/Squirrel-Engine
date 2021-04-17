#pragma once
#include "NJob.h"

class NJ_Input final : public NJob
{
public:
	NJ_Input();
	void mount() override;
	void unmount() override;
	void run() override;
};
