#pragma once
#include <iostream>

namespace Squirrel
{
	enum EJobClass
	{
		Window_CreateWindow,
		Window_RenderWindow

	};
	enum class EJobType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	#define BIT(x) (1 << x)
	enum EJobCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	enum EJobPriority
	{
		LOW,
		MEDIUM,
		HIGH,
		CRITICAL
	};
	
	class Job
	{
	public:
		EJobType		jobType;
		EJobCategory	jobCategory;
		EJobPriority	jobPriority;
		int jobID;
		Job(EJobType jtype, EJobCategory jcategory, EJobPriority Ejpriority, int jid);
		Job();
		virtual void Setup() = 0;
		virtual void Run() = 0;
	};
}
