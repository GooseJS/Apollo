#pragma once

#include "Apollo/event/EventSystem.h"

namespace Apollo
{
    struct EventWindowOpen : public IEventCancellable
    {
        EventWindowOpen() : IEventCancellable() {}
    };

    struct EventWindowClose : public IEvent
    {
        EventWindowClose() : IEvent() {}
    };

    struct EventWindowOpened : public IEvent
    {
        EventWindowOpened() : IEvent() {}
    };
}