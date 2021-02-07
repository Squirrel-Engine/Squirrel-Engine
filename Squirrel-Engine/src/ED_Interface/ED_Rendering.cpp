#pragma once
#include "ED_Rendering.h"
#include "NotImplementedEditorFunctionException.h"
namespace Squirrel
{
	namespace Rendering
	{

		GLFWwindow* GetRenderingWindow()
		{
			return InterfaceFactory::getInstance()->getRDInterface()->getGlfwWindow();
		}


		int GetCurrentFPS()
		{
			throw NotImplementedEditorFunctionException;
		}
	}
}