#pragma once
#include <dsound.h>
#include "Actor.h"
#include "InterfaceFactory.h"

#define MAX_AUDIO_BUF 4 
#define BUFFERNOTIFYSIZE 192000

SR_COMPONENT()
class 	AudioComponent : public ActorComponent
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
	void thFunc();

	IDirectSound8* m_pDS = NULL;
	IDirectSoundBuffer8* m_pDSBuffer8 = NULL;	//used to manage sound buffers.
	IDirectSoundBuffer* m_pDSBuffer = NULL;
	IDirectSoundNotify8* m_pDSNotify = NULL;
	DSBPOSITIONNOTIFY m_pDSPosNotify[MAX_AUDIO_BUF];
	HANDLE m_event[MAX_AUDIO_BUF];
	DSBUFFERDESC dsbd;

	BOOL isPlaying = TRUE;
	LPVOID buf = NULL;
	DWORD  buf_len = 0;
	DWORD res = WAIT_OBJECT_0;
	DWORD offset = BUFFERNOTIFYSIZE;

	int sample_rate = 44100;	//PCM sample rate
	int channels = 2;			//PCM channel number
	int bits_per_sample = 16;	//bits per sample
	int audioSourceID;
	float audioVolume;
};
SR_COMPONENT()