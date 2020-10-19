//
// Created by Fatih Canbekli on 29.09.2020.
//

#pragma once
#include <iostream>

#include "JobFactory.h"

namespace Squirrel{
    class RuntimeManager {
    private:
        RuntimeManager();
        static RuntimeManager* instance;

    public:
        static RuntimeManager* getInstance();
        void engineStartup();
        void engineShutdown();
    };
}




