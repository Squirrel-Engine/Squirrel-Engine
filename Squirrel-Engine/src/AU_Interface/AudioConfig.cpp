#include "AudioConfig.h"

Squirrel::AudioConfig::AudioConfig()
{
	setup();
}

void Squirrel::AudioConfig::setup()
{
	nlohmann::json conMap = jsonConfigurator->parseFile_json();
	if (conMap["Audio_Engine"] == "Ear") {
		audioEngine = EAudioEngine::EAR;
	}
}
