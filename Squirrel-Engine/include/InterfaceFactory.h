#pragma once
#include "RD_Interface.h"
#include "MT_Interface.h"
namespace Squirrel
{
	class InterfaceFactory
	{
	private:
		// Singleton
		InterfaceFactory();
		static InterfaceFactory* instance;

		// Interface Pointers
	public:
		// Getter Setter
		RD_Interface getRDInterface();
		MT_Interface getMTInterface();
		static InterfaceFactory* getInstance();
		RD_Interface rd_Interface;
		MT_Interface mt_Interface;
	};
}
