#include "NJ_InitializeRender.h"

NJ_InitializeRender::NJ_InitializeRender()
{
}

void NJ_InitializeRender::mount()
{
}

void NJ_InitializeRender::unmount()
{
}

void NJ_InitializeRender::run()
{
	InterfaceFactory::getInstance().getRDInterface().render();
}
