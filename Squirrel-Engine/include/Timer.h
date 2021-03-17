#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	float setTimeStamp();
	float getTimeStamp();
private:
	std::chrono::steady_clock::time_point last;
};

