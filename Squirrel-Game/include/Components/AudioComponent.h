#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dsound.h>
#include <iostream>

#include "Macros.h"
#include "../../Squirrel-Engine/include/Actor.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"

#define MAX_AUDIO_BUF 4 
#define BUFFERNOTIFYSIZE 192000

SR_COMPONENT()
class AudioComponent : public ActorComponent
{
public:
	AudioComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	SR_VAR_START()
		int C_AudioSourceID;
		float C_AudioVolume;
	SR_VAR_END()
	
public:
	void setAudioSource(int sourceID);
	void setAudioVolume(float volume);

	int getActiveAudioSource();
	int getAudioVolume();
	
	void play();
	void stop();
private:
	int audioSourceID;
	float audioVolume;
};
SR_COMPONENT()