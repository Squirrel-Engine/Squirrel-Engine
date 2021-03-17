#pragma once
#include <iostream>
#include <thread> 
#include "JobFactory.h"

namespace Squirrel{
    class RuntimeManager {
    public:
        RuntimeManager();

        static RuntimeManager& getInstance();
        void engineStartup();
        void engineShutdown();
    };
}