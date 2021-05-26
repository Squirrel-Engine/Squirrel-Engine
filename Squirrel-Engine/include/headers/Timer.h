#pragma once

class Timer
{
public:
	Timer() {}
	static void update();
	static float getSeconds()  { return m_Time; };
	static float getMiliSeconds() { return m_Time * 1000.0f; };
	static float getTime() { return (float)glfwGetTime(); };
	static float getFps();
private:
	static float m_Time;
	static float m_lastFrame;
};
