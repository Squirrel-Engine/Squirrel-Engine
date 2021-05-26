#include "Timer.h"
#include "pch.h"

float Timer::m_Time = 0;
float Timer::m_lastFrame = 0;

void  Timer::update()
{
	float time = getTime();
	m_Time = time - m_lastFrame;
	m_lastFrame = time;
}

float Timer::getFps() {
	return 1/m_Time;
}

