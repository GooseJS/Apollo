#pragma once

#include <map>
#include <list>
#include <functional>

#include "Apollo/event/IEvents.h"

namespace Apollo
{
    using std::map;
    using std::list;
    using std::pair;
    using std::multimap;

    class EventSystem
    {
    public:
        typedef std::function<void(IEvent&)> EventFunction;
        typedef std::multimap<const std::type_info*, const EventFunction> EventMap;
    private:
        //list<EventPointer> _currentEvents;
        EventMap _eventDB;
    private:
        EventSystem() = default;
        ~EventSystem() = default;
        EventSystem(const EventSystem& es) {}
        EventSystem& operator=(const EventSystem& es) {}

    public:
        static EventSystem* getInstance();

        template<typename EventType>
        void addListener(EventFunction listenerFunction)
        {
            _eventDB.insert(std::make_pair(&typeid(EventType), listenerFunction));
        }

        template<typename EventType>
        void dispatchEvent(EventType& event)
        {
            auto range = _eventDB.equal_range(&typeid(event));

            for (auto iter = range.first; iter != range.second; iter++)
            {
                iter->second(event);
            }
        }
    };
}