#include "GM_Interface.h"

GM_Interface::GM_Interface()
{
	levelStore = new LevelStore();
	lightManager = new DynamicLightManager;
}

void GM_Interface::configureComponents()
{
	for (auto& actor : levelStore->actors) {
		for (auto& component : actor->componentList)
		{
			component.second->setup();
		}
	}
	for (auto& lights : levelStore->lights) {
		for (auto& component : lights->componentList)
		{
			component.second->setup();
		}
	}
	for (auto& component : levelStore->mainCamera->componentList)
	{
		component.second->setup();
	}
}
