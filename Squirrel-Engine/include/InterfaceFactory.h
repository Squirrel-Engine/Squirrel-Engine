#pragma once
#include "GM_Interface.h"
#include "RD_Interface.h"
#include "MT_Interface.h"
#include "RM_Interface.h"

namespace Squirrel
{
	class InterfaceFactory
	{
	private:
		// Singleton
		InterfaceFactory() {};
		~InterfaceFactory() {};

		RD_Interface rd_Interface;
		MT_Interface mt_Interface;
		GM_Interface gm_Interface;
		RM_Interface rm_Interface;
	public:
		// Getter Setter
		RD_Interface& getRDInterface();
		MT_Interface& getMTInterface();
		GM_Interface& getGMInterface();
		RM_Interface& getRMInterface();
		static InterfaceFactory& getInstance();
	};

	
}
