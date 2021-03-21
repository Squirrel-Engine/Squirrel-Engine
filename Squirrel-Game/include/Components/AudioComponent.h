#pragma once

#include "../../Squirrel-Engine/include/Actor.h"
#include "Macros.h"

SR_COMPONENT()
class 	AudioComponent : public Squirrel::ActorComponent
{
private:
	void BeginPlay() override;
	void Update() override;
	void setup() override;
	int audioSourceID;
	float audioVolume;
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
};
SR_COMPONENT()