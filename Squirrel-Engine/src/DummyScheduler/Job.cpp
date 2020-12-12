#include "include/Job.h"
namespace Squirrel
{
	Job::Job()
	{
		
	}

	Job::Job(EJobCategory JClass, EJobPriority JPriority)
	{
		jobCategory = JClass;
		jobPriority = JPriority;
	}
}
