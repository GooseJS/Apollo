#pragma once

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#define EXTERNC extern "C"

#ifdef APOLLO_PLATFORM_LINUX
    #if __GNUC__ >= 4
        #define APOLLO __attribute__ ((visibility("default")))
    #else
        #define APOLLO
    #endif
#endif