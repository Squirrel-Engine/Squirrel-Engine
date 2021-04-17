#pragma once
#include "Fur.h"
#include "Configuration.h"
#include <iostream>
#include <string.h>

class RD_Interface
{
public:
	RD_Interface() {}
	~RD_Interface() {}
	void startRenderEngine();
	void pauseRenderEngine();
	void stopRenderEngine();

	void render();
	void addActorToRenderQueue(); // Deprecated
	void submitDrawCall(DrawCall& drawCall);

	//TODO: Refactoring Point
	void updateRenderEngineOptions(std::string parameterName, int parameter);
	void updateRenderEngineOptions(std::string parameterName, float parameter);
	void updateRenderEngineOptions(std::string parameterName, std::string parameter);

	int frameCounter = 0;
private:
	Fur::Fur fur;
};

