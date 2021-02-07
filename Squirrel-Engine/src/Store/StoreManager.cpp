#include "StoreManager.h"

namespace Squirrel
{
	StoreManager::StoreManager()
	{
		levelStore = new LevelStore();

		
		//Store Setup
		levelStore->setupStore();
	}

	


	//Singleton
	
	StoreManager* StoreManager::instance = 0;
	StoreManager* StoreManager::getInstance()
	{
		if(instance == 0)
		{
			instance = new StoreManager();
		}
		return instance;
	}

	//Store Getters

	LevelStore* StoreManager::getLevelStore()
	{
		return levelStore;
	}

}
