#include "AudioConfig.h"

AudioConfig::AudioConfig()
{
	setup();
}

void AudioConfig::setup()
{
	nlohmann::json conMap = jsonConfigurator->parseFile_json();
	if (conMap["Audio_Engine"] == "Ear") {
		audioEngine = EAudioEngine::EAR;
	}
}
