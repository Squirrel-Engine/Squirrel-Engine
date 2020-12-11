#include "include/MT_Interface.h"

#include "include/Configuration.h"
#include "include/NotImplementedSchedulerException.h"

namespace Squirrel
{
	MT_Interface::MT_Interface()
	{
		//TODO: Get Rid of RenderDebug Option
		renderDebug = Configuration::getInstance()->schedulerConfig.renderDebug;
		if (renderDebug == false)
		{
			dummyScheduler = new DummyScheduler(ESchedulerMode::OPERATIONAL);
		}
		else if (renderDebug == true)
		{
			dummyScheduler = new DummyScheduler(ESchedulerMode::RENDER_DEBUG);
		}
		
	}

	
	void MT_Interface::startScheduler()
	{
		try
		{
			switch (Configuration::getInstance()->schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				dummyScheduler->startScheduler();
				break;
			case EScheduler::Nut:
				throw NotImplementedSchedulerException;
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
			switch (Configuration::getInstance()->schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				dummyScheduler->stopScheduler();
				break;
			case EScheduler::Nut:
				throw NotImplementedSchedulerException;
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
			switch (Configuration::getInstance()->schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				dummyScheduler->pauseScheduler();
				break;
			case EScheduler::Nut:
				throw NotImplementedSchedulerException;
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
