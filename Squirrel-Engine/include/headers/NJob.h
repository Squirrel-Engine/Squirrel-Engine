#pragma once
#include "EJobStage.h"

class NJob
{
public:
	virtual ~NJob() = default;

	virtual void mount() = 0;
	virtual void unmount() = 0;
	virtual void run() = 0;
};
