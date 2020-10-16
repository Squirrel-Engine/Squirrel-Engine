#pragma once
#include <exception>
#include <iostream>

#include "Configuration.h"

namespace Squirrel
{
    class NotImplementedSchedulerException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "This Scheduler is Not Yet Implemented";
        }
    } NotImplementedSchedulerException;

}
