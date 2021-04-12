#include "Components/AudioComponent.h"





AudioComponent::AudioComponent()
{
	
}

void AudioComponent::BeginPlay()
{

}

void AudioComponent::Update()
{

}

void AudioComponent::setup()
{
	audioSourceID = C_AudioSourceID;
	audioVolume = C_AudioVolume;


	//SetConsoleTitle(TEXT("Simplest Audio Play DirectSound"));//Console Title
	//Init DirectSound
	if (FAILED(DirectSoundCreate8(NULL, &m_pDS, NULL)))
		std::cout << "Error" << std::endl;;
	if (FAILED(m_pDS->SetCooperativeLevel(FindWindow(NULL, TEXT("Simplest Audio Play DirectSound")), DSSCL_NORMAL)))
		std::cout << "Error" << std::endl;;



	memset(&dsbd, 0, sizeof(dsbd));
	dsbd.dwSize = sizeof(dsbd);
	dsbd.dwFlags = DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLPOSITIONNOTIFY | DSBCAPS_GETCURRENTPOSITION2;
	dsbd.dwBufferBytes = MAX_AUDIO_BUF * BUFFERNOTIFYSIZE;
	//WAVE Header
	dsbd.lpwfxFormat = (WAVEFORMATEX*)malloc(sizeof(WAVEFORMATEX));
	dsbd.lpwfxFormat->wFormatTag = WAVE_FORMAT_PCM;
	/* format type */
	(dsbd.lpwfxFormat)->nChannels = channels;
	/* number of channels (i.e. mono, stereo...) */
	(dsbd.lpwfxFormat)->nSamplesPerSec = sample_rate;
	/* sample rate */
	(dsbd.lpwfxFormat)->nAvgBytesPerSec = sample_rate * (bits_per_sample / 8) * channels;
	/* for buffer estimation */
	(dsbd.lpwfxFormat)->nBlockAlign = (bits_per_sample / 8) * channels;
	/* block size of data */
	(dsbd.lpwfxFormat)->wBitsPerSample = bits_per_sample;
	/* number of bits per sample of mono data */
	(dsbd.lpwfxFormat)->cbSize = 0;

	//Creates a sound buffer object to manage audio samples. 
	HRESULT hr1;
	if (FAILED(m_pDS->CreateSoundBuffer(&dsbd, &m_pDSBuffer, NULL))) {
		std::cout << "Error" << std::endl;;
	}
	if (FAILED(m_pDSBuffer->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&m_pDSBuffer8))) {
		std::cout << "Error" << std::endl;;
	}
	//Get IDirectSoundNotify8
	if (FAILED(m_pDSBuffer8->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&m_pDSNotify))) {
		std::cout << "Error" << std::endl;;
	}
	for (int i = 0; i < MAX_AUDIO_BUF; i++) {
		m_pDSPosNotify[i].dwOffset = i * BUFFERNOTIFYSIZE;
		m_event[i] = ::CreateEvent(NULL, false, false, NULL);
		m_pDSPosNotify[i].hEventNotify = m_event[i];
	}
	m_pDSNotify->SetNotificationPositions(MAX_AUDIO_BUF, m_pDSPosNotify);
	m_pDSNotify->Release();

	//Start Playing
	BOOL isPlaying = TRUE;
	LPVOID buf = NULL;
	DWORD  buf_len = 0;
	DWORD res = WAIT_OBJECT_0;
	DWORD offset = BUFFERNOTIFYSIZE;

	m_pDSBuffer8->SetCurrentPosition(0);
	m_pDSBuffer8->Play(0, 0, DSBPLAY_LOOPING);
}

void AudioComponent::thFunc()
{
	while (isPlaying) {
		if ((res >= WAIT_OBJECT_0) && (res <= WAIT_OBJECT_0 + 3)) {
			m_pDSBuffer8->Lock(offset, BUFFERNOTIFYSIZE, &buf, &buf_len, NULL, NULL, 0);
			if (fread(buf, 1, buf_len, Squirrel::InterfaceFactory::getInstance().getRMInterface().getAudio(audioSourceID)->audioObject) != buf_len) {
				//File End
				//Loop:
				fseek(Squirrel::InterfaceFactory::getInstance().getRMInterface().getAudio(audioSourceID)->audioObject, 0, SEEK_SET);
				fread(buf, 1, buf_len, Squirrel::InterfaceFactory::getInstance().getRMInterface().getAudio(audioSourceID)->audioObject);
				//Close:
				isPlaying=0;
			}
			m_pDSBuffer8->Unlock(buf,buf_len,NULL,0);
			offset += buf_len;
			offset %= (BUFFERNOTIFYSIZE * MAX_AUDIO_BUF);
			printf("this is %7d of buffer\n", offset);
		}
		res = WaitForMultipleObjects(MAX_AUDIO_BUF, m_event, FALSE, INFINITE);
	}
}

int AudioComponent::getActiveAudioSource()
{
	return audioSourceID;
}

int AudioComponent::getAudioVolume()
{
	return audioVolume;
}

void AudioComponent::play()
{
	std::thread the(&AudioComponent::thFunc, this);
	the.detach();
}
