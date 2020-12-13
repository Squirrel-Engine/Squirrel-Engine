#pragma once
#include "include/ED_Engine.h"

#include "include/Configuration.h"


namespace Squirrel
{
	namespace Engine
	{
		std::string GetEngineVersion()
		{
			//TODO: Get This From Data Store
			return "V0.2";
		}

		std::string GetRenderEngineName()
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				return "Fur";
			}
		}

		std::string GetSchedulerName()
		{
			switch (Configuration::getInstance()->schedulerConfig.scheduler)
			{
			case EScheduler::DummyScheduler:
				return "DummyScheduler";
			case EScheduler::Nut:
				return "Nut";
			}
		}



	}


}
