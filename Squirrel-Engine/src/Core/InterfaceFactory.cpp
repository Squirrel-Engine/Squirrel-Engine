#include "include/InterfaceFactory.h"

namespace Squirrel
{
	InterfaceFactory::InterfaceFactory()
	{
		MT_Interface* mt_Interface = new MT_Interface();
		RD_Interface* rd_Interface = new RD_Interface();
	}

	
	MT_Interface InterfaceFactory::getMTInterface(){
		return mt_Interface;
	}
	InterfaceFactory* InterfaceFactory::instance = 0;
	InterfaceFactory* InterfaceFactory::getInstance()
	{
		if (instance == 0)
		{
			instance = new InterfaceFactory();
		}
		return instance;
	}

	RD_Interface InterfaceFactory::getRDInterface()
	{
		return rd_Interface;
	}
}
