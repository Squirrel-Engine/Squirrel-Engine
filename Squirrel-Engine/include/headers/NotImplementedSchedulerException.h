#pragma once
#include <exception>
#include "Configuration.h"


class NotImplementedSchedulerException : public std::exception
{
	const char* what() const throw() override
	{
		return "This Scheduler is Not Yet Implemented";
	}
} NotImplementedSchedulerException;
