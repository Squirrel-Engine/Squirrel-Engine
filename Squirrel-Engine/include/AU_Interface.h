#pragma once
#include "Ear.h"

class AU_Interface
{
public:
	AU_Interface();
	void startAudioEngine();
	void playAudio();

private:
	// Options
	// Audio Engine
	Ear* ear;
};

