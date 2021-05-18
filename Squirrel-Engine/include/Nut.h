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
	void submitJob(NJob& job, EQueueOrder order);
private:
	void schedular();
	void threadPoolProcess();
	NJob* threadPoolSchedular();
	void processLowOrder();
	void processHighOrder();

private:
	std::queue<NJob*> jobQueueLowOrder;
	std::queue<NJob*> jobQueueHighOrder;
	bool multithreded;
};
