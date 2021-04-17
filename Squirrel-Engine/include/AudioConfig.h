#pragma once
#include "EAudioEngine.h"
#include "IConfig.h"
#include "JSONParser.h"


class AudioConfig : IConfig
{
public:
	AudioConfig();
	EAudioEngine audioEngine;
	void setup() override;

private:
	JSONParser* jsonConfigurator = new JSONParser("../../Squirrel-Engine/src/configs/audioConfig.json");
};

