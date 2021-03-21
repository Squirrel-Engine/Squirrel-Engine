#include "InterfaceFactory.h"

namespace Squirrel
{
	InterfaceFactory& InterfaceFactory::getInstance()
	{
		static InterfaceFactory instance;
		return instance;
	}

	RD_Interface& InterfaceFactory::getRDInterface()
	{
		return rd_Interface;
	}

	MT_Interface& InterfaceFactory::getMTInterface()
	{
		return mt_Interface;
	}

	GM_Interface& InterfaceFactory::getGMInterface()
	{
		return gm_Interface;
	}

	RM_Interface& InterfaceFactory::getRMInterface()
	{
		return rm_Interface;
	}

	AU_Interface& InterfaceFactory::getAUInterface()
	{
		return au_Interface;
	}
}
