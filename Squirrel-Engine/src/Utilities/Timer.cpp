#include "Timer.h"

Timer::Timer()
{
	last = std::chrono::steady_clock::now();
}

float Timer::getTimeStamp()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float Timer::setTimeStamp()
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
