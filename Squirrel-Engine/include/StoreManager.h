#pragma once
#include "LevelStore.h"
namespace Squirrel
{
	class StoreManager
	{
	private:
		StoreManager();
		static StoreManager* instance;

		
		//Stores
		LevelStore* levelStore;
	public:
		static StoreManager* getInstance();


		
		LevelStore* getLevelStore();
		

		
	};	
}
