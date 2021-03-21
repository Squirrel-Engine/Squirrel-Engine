#pragma once
#include "EAudioEngine.h"
#include "IConfig.h"
#include "JSONParser.h"

namespace Squirrel {

	class AudioConfig : Squirrel::IConfig
	{
	public:
		AudioConfig();
		EAudioEngine audioEngine;
		void setup() override;

	private:
		Squirrel::JSONParser* jsonConfigurator = new Squirrel::JSONParser("../../Squirrel-Engine/src/configs/audioConfig.json");
	};

}