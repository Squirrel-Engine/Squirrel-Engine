#pragma once
#include <iostream>

namespace Squirrel
{
	enum JobClass
	{
		J_Window_CreateWindow

	};
	enum class JobType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	#define BIT(x) (1 << x)
	enum JobCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	enum JobPriority
	{
		
		LOW,
		MEDIUM,
		HIGH,
		CRITICAL
	};
	
	class Job
	{
	public:
		JobType		jobType;
		JobCategory	jobCategory;
		JobPriority	jobPriority;
		int jobID;
		Job(JobType jtype, JobCategory jcategory, JobPriority jpriority, int jid);
		virtual void Run() = 0;
	};
}
