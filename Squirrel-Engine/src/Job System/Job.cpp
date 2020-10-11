#include "include/Job.h"
namespace Squirrel
{
	Job::Job(JobType jtype, JobCategory jcategory, JobPriority jpriority, int jid)
	{
		jobType = jtype;
		jobCategory = jcategory;
		jobPriority = jpriority;
		jobID = jid;
	}
}
