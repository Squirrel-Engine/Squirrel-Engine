#pragma once
#include "GM_Interface.h"
#include "RD_Interface.h"
#include "MT_Interface.h"
namespace Squirrel
{
	class InterfaceFactory
	{
	private:
		// Singleton
		InterfaceFactory();
		
		RD_Interface* rd_Interface;
		MT_Interface* mt_Interface;
		GM_Interface* gm_interface;
		static InterfaceFactory* instance;
	public:
		// Getter Setter
		RD_Interface* getRDInterface();
		MT_Interface* getMTInterface();
		GM_Interface* getGMInterface();
		static InterfaceFactory* getInstance();
	};
}
