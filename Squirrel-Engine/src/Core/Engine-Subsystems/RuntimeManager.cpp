#include "RuntimeManager.h"
#include "InterfaceFactory.h"
#include "StoreManager.h"
#include <dsound.h>
namespace Squirrel{
    RuntimeManager::RuntimeManager() {

    }

    RuntimeManager& RuntimeManager::getInstance(){
        static RuntimeManager instance;
        return instance;
    }

    void RuntimeManager::engineStartup() {
        std::cout << "Engine is Loading" << std::endl;

        //Interface Initialization
        IDirectSound8* m_pDS = NULL;
        InterfaceFactory::getInstance().getAUInterface().startAudioEngine();
        InterfaceFactory::getInstance().getRDInterface().startRenderEngine();
        InterfaceFactory::getInstance().getRMInterface().loadAssetMT();

    	//!!!------------------------------------------------------------------------------------------------------------------------------------------------------------















    	
        //!!!------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Store Allocation
        //renderStore = (struct RenderStore*)malloc(sizeof(struct RenderStore));
        //jobFactory = (struct JobFactory*)malloc(sizeof(struct JobFactory));
    	// Job Queue Allocation
        // Memory Allocation

        // Set Configurations

        // Configure Profiler
    }

    void RuntimeManager::engineShutdown() {
        std::cout << "Shutdown" << std::endl;

        // Memory Deallocation

        // Export Log History
    }
}
