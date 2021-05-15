#include "GM_Interface.h"

GM_Interface::GM_Interface()
{
	levelStore = new LevelStore();
	lightManager = new DynamicLightManager;
}
