#pragma once
#include "EQueueOrder.h"
#include "NJob.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>

class Nut
{
public:
	Nut();
	void startScheduler();
	void stopScheduler();
	void pauseScheduler();
	void schedular();
	void submitJob(NJob& job, EQueueOrder order);
private:
	std::queue<NJob*> jobQueueLowOrder;
	std::queue<NJob*> jobQueueHighOrder;
};
