#pragma once

#include <spdlog/spdlog.h>
#include "Apollo/Core.h"

namespace Apollo
{
    class APOLLO Logger
    {
    private:
        static std::shared_ptr<spdlog::logger> _coreLogger;
        static std::shared_ptr<spdlog::logger> _clientLogger;
        static bool _init;
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _clientLogger; }
    };
}

#define APOLLO_CORE_TRACE(...)   ::Apollo::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define APOLLO_CORE_INFO(...)    ::Apollo::Logger::getCoreLogger()->info(__VA_ARGS__)
#define APOLLO_CORE_WARN(...)    ::Apollo::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define APOLLO_CORE_ERROR(...)   ::Apollo::Logger::getCoreLogger()->error(__VA_ARGS__)
#define APOLLO_CORE_CRITICAL(...)   ::Apollo::Logger::getCoreLogger()->critical(__VA_ARGS__)

#define APOLLO_TRACE(...)   ::Apollo::Logger::getClientLogger()->trace(__VA_ARGS__)
#define APOLLO_INFO(...)    ::Apollo::Logger::getClientLogger()->info(__VA_ARGS__)
#define APOLLO_WARN(...)    ::Apollo::Logger::getClientLogger()->warn(__VA_ARGS__)
#define APOLLO_ERROR(...)   ::Apollo::Logger::getClientLogger()->error(__VA_ARGS__)
#define APOLLO_CRITICAL(...)   ::Apollo::Logger::getClientLogger()->critical(__VA_ARGS__)