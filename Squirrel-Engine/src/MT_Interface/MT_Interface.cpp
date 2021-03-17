#include "MT_Interface.h"
#include "Configuration.h"
#include "NotImplementedSchedulerException.h"

namespace Squirrel
{
	MT_Interface::MT_Interface()
	{
		nut = new Nut();
		//TODO: Get Rid of RenderDebug Option
		renderDebug = Configuration::getInstance().schedulerConfig.renderDebug;
		if (renderDebug == false)
		{
			dummyScheduler = new DummyScheduler(ESchedulerMode::OPERATIONAL);
			nut = new Nut();
		}
		else if (renderDebug == true)
		{
			dummyScheduler = new DummyScheduler(ESchedulerMode::RENDER_DEBUG);
			nut = new Nut();
		}
		
	}

	
	void MT_Interface::startScheduler()
	{
		try
		{
			switch (Configuration::getInstance().schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				dummyScheduler->startScheduler();
				break;
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
			case EScheduler::DummyScheduler:
				dummyScheduler->stopScheduler();
				break;
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
			case EScheduler::DummyScheduler:
				dummyScheduler->pauseScheduler();
				break;
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

	void MT_Interface::submitJob(NJob* job)
	{
		try
		{
			switch (Configuration::getInstance().schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				throw NotImplementedSchedulerException;
				break;
			case EScheduler::Nut:
				nut->submitJob(job);
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


}
