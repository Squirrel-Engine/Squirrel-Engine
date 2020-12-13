#pragma once
#include <exception>
#include <iostream>

namespace Squirrel
{
    class NotImplementedEditorFunctionException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "This Editor Function is Not Yet Implemented";
        }
    } NotImplementedEditorFunctionException;

}
