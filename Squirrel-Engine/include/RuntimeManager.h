//
// Created by Fatih Canbekli on 29.09.2020.
//

#ifndef SQUIRREL_RUNTIMEMANAGER_H
#define SQUIRREL_RUNTIMEMANAGER_H
#include <iostream>

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



#endif //SQUIRREL_RUNTIMEMANAGER_H
