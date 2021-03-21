#include "Components/AudioComponent.h"


void AudioComponent::setup()
{
	audioSourceID = C_AudioSourceID;
	audioVolume = C_AudioVolume;
}

int AudioComponent::getActiveAudioSource()
{
	return audioSourceID;
}

int AudioComponent::getAudioVolume()
{
	return audioVolume;
}
