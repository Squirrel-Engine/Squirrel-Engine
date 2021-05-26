#include "Audio.h"

Audio::Audio(std::string filename)
{
	if ((audioObject = fopen(filename.c_str(), "rb")) == NULL) {
		std::cout << "cannot open file located at " + filename << std::endl;
	}
}
