#include "include/Job.h"
namespace Squirrel
{
	Job::Job()
	{
		
	}

	Job::Job(EJobType jtype, EJobCategory jcategory, EJobPriority jpriority, int jid)
	{
		jobType = jtype;
		jobCategory = jcategory;
		jobPriority = jpriority;
		jobID = jid;
	}
}
