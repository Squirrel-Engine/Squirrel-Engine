#pragma once
#include "Jobs.h"
#include "MockStateManager.h"
namespace Squirrel
{
	class JobFactory
	{
	public:
		void createJob(EJobClass jclass);
	};
}
