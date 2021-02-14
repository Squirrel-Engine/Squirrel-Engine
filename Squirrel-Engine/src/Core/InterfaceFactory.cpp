#include "InterfaceFactory.h"

namespace Squirrel
{
	InterfaceFactory::InterfaceFactory()
	{
		mt_Interface = new MT_Interface();
		rd_Interface = new RD_Interface();
		rm_Interface = new RM_Interface();
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

	RD_Interface* InterfaceFactory::getRDInterface()
	{
		return rd_Interface;
	}

	MT_Interface* InterfaceFactory::getMTInterface()
	{
		return mt_Interface;
	}

	GM_Interface* InterfaceFactory::getGMInterface()
	{
		return gm_interface;
	}

	RM_Interface* InterfaceFactory::getRMInterface()
	{
		return rm_Interface;
	}
}
