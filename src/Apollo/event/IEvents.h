#pragma once

namespace Apollo
{
    struct IEvent
    {
        virtual ~IEvent() = default;
    };

    struct IEventCancellable : public IEvent
    {
        void cancel(bool cancelled) { _cancelled = cancelled; }
        bool cancelled() const { return _cancelled; }
        virtual ~IEventCancellable() = default;
    private:
        bool _cancelled = false;
    };

//    template<typename EventType>
//    struct Event
//    {
//        EventType _event;
//
//        EventType operator()() { return _event; }
//    };
}