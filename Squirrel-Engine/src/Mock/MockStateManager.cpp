#include "include/MockStateManager.h"

namespace Squirrel
{
    MockStateManager* MockStateManager::instance = 0;

    MockStateManager* MockStateManager::getInstance()
    {
        if (instance == 0)
        {
            instance = new MockStateManager();
        }

        return instance;
    }

    MockStateManager::MockStateManager()
    {
        width = 800;
        height = 600;
        windowName = "TEST";
    }
}
