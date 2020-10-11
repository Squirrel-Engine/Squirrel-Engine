#pragma once
#include <string>
#include <queue>
#include "Window.h"
#include "Jobs.h"

namespace Squirrel
{
    class MockStateManager
    {
    private:
        MockStateManager();
        static MockStateManager* instance;

    public:
        std::queue<Job*> JobQueue;
		static MockStateManager* getInstance();
        Squirrel::Window window;
        int height;
        int width;
        std::string windowName;
    };
}


