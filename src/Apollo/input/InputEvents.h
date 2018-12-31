#pragma once

#include "Apollo/event/EventSystem.h"

namespace Apollo
{
    struct EventKeyboard : public IEvent
    {
    private:
        const int _key;
        const int _scancode;
        const int _action;
        const int _mods;
    public:
        EventKeyboard(int key, int scancode, int action, int mods) : _key(key), _scancode(scancode), _action(action), _mods(mods) {}

        int key() const { return _key; }
        int scancode() const { return _scancode; }
        int action() const { return _action; }
        int mods() const { return _mods; }
    };

    struct EventKeyPressed : public IEvent
    {
    private:
        const int _key;
        const int _scancode;
        const int _mods;
    public:
        EventKeyPressed(int key, int scancode, int mods) : _key(key), _scancode(scancode), _mods(mods)
        {}

        int key() const { return _key; }
        int scancode() const { return _scancode; }
        int mods() const { return _mods; }

    };

    struct EventKeyReleased : public IEvent
    {
    private:
        const int _key;
        const int _scancode;
        const int _mods;
    public:
        EventKeyReleased(int key, int scancode, int mods) : _key(key), _scancode(scancode), _mods(mods) {}

        int key() const { return _key; }
        int scancode() const { return _scancode; }
        int mods() const { return _mods;   }
    };
}