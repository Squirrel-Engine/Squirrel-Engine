#include "include/RuntimeManager.h"

namespace Squirrel{

    RuntimeManager* RuntimeManager::instance = nullptr;
    RuntimeManager::RuntimeManager() {

    }

    RuntimeManager * RuntimeManager::getInstance(){
        if (instance == 0){
            instance = new RuntimeManager();
        }
        return instance;
    }

    void RuntimeManager::engineStartup() {
        std::cout << "Engine is Loading" << std::endl;

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