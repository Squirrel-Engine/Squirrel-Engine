#include "MT_Interface.h"
#include "Configuration.h"
#include "NotImplementedSchedulerException.h"


MT_Interface::MT_Interface()
{
	nut = new Nut();
	//TODO: Get Rid of RenderDebug Option
}


void MT_Interface::startScheduler()
{
	try
	{
		switch (Configuration::getInstance().schedulerConfig.scheduler)
		{
		case EScheduler::Nut:
			nut->startScheduler();
			break;
		default:
			std::cout << "No Scheduler Has Been Configured" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void MT_Interface::stopScheduler()
{
	try
	{
		switch (Configuration::getInstance().schedulerConfig.scheduler)
		{
		case EScheduler::Nut:
			nut->stopScheduler();
		default:
			std::cout << "No Scheduler Has Been Configured" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void MT_Interface::pauseScheduler()
{
	try
	{
		switch (Configuration::getInstance().schedulerConfig.scheduler)
		{
		case EScheduler::Nut:
			nut->pauseScheduler();
		default:
			std::cout << "No Scheduler Has Been Configured" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void MT_Interface::submitJob(NJob& job, EQueueOrder order)
{
	try
	{
		switch (Configuration::getInstance().schedulerConfig.scheduler)
		{
		case EScheduler::Nut:
			nut->submitJob(job, order);
			break;
		default:
			std::cout << "No Scheduler Has Been Configured" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
