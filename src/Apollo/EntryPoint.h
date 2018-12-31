#pragma once

#include "Apollo/Application.h"

#ifdef APOLLO_PLATFORM_LINUX

extern Apollo::Application* Apollo::createApplication();

int main(int argc, char** argv)
{
    auto app = Apollo::createApplication();
    app->run();
    delete app;
}

#else
    #eror Only support Linux rn bop
#endif