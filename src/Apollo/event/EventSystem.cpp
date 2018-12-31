#include <Apollo.h>
#include "EventSystem.h"

namespace Apollo
{
    EventSystem *EventSystem::getInstance()
    {
        static EventSystem instance;
        return &instance;
    }
}