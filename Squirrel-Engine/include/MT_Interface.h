#pragma once
#include "EQueueOrder.h"
#include "Nut.h"

class MT_Interface
{
public:
	MT_Interface();
	void startScheduler();
	void stopScheduler();
	void pauseScheduler();

	void submitJob(NJob& job, EQueueOrder order);

private:
	// Options
	bool renderDebug;

	// Schedulers
	Nut* nut;
};
