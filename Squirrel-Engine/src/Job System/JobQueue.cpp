#include "include/JobQueue.h"

namespace Squirrel
{
	std::queue<Job*> JobQueue::lowPriJobQueue;
	std::queue<Job*> JobQueue::midPriJobQueue;
	std::queue<Job*> JobQueue::highPriJobQueue;
	std::queue<Job*> JobQueue::criticalPriJobQueue;
}
