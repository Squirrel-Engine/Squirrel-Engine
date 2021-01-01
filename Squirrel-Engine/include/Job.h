#pragma once

namespace Squirrel
{
	enum class EJobClass
	{
		Window_CreateWindow, //ClassID: 0
		Window_RenderWindow, //ClassID: 1
	};

	
	enum class EJobCategory
	{
		Render,
		Core,
		Window,
		AI,
	};

	enum EJobPriority
	{
		Low,
		Medium, 
		High,
		Critical
	};
	
	class Job
	{
	public:
		virtual ~Job() {}

		virtual void mount() = 0;
		virtual void unmount() = 0;
		virtual void run() = 0;
	};
}
