#include "SchedulerConfig.h"

namespace Squirrel
{
	void SchedulerConfig::setup()
	{
		nlohmann::json conMap = jsonConfigurator->parseFile_json();
		if (conMap["Scheduler"] == "DummyScheduler") {
			scheduler = EScheduler::DummyScheduler;
		}
		if (conMap["Scheduler"] == "Nut") {
			scheduler = EScheduler::Nut;
		}
		if (conMap["MT_Mode"] == "On") {
			mtMode = true;
		}
		if (conMap["MT_Mode"] == "Off") {
			mtMode = false;
		}
		if (conMap["Render_Debug"] == "On") {
			renderDebug = true;
		}
		if (conMap["Render_Debug"] == "Off") {
			renderDebug = false;
		}
	}

}
