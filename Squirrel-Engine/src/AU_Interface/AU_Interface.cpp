#include "AU_Interface.h"

#include "Configuration.h"

namespace Squirrel
{
	AU_Interface::AU_Interface()
	{
		ear = new Ear();
	}

	void AU_Interface::startAudioEngine()
	{
		try
		{
			switch (Configuration::getInstance().audioConfig.audioEngine)
			{
			case EAudioEngine::EAR:
				ear->startAudioEngine();
				break;
			default:
				std::cout << "No Audio Engine Has Been Configured" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

	}

	void AU_Interface::playAudio()
	{
		try
		{
			switch (Configuration::getInstance().audioConfig.audioEngine)
			{
			case EAudioEngine::EAR:
				ear->playAudio();
				break;
			default:
				std::cout << "No Audio Engine Has Been Configured" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}
