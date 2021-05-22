#pragma once
#include "LevelStore.h"
#include "DynamicLightManager.h"

class GM_Interface
{
public:
	GM_Interface();
	LevelStore* levelStore;
	DynamicLightManager* lightManager;
public:
	void configureComponents();
};
