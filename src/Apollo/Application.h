#pragma once

#include <iostream>
#include <gstl/collections/String.h>

#include "Apollo/Core.h"

namespace Apollo
{
    class APOLLO Application
    {
    public:
        Application();
        virtual ~Application();

        virtual void onUpdate() {}
        virtual void onRender() {}

        void run();

        void createWindow(int width, int height, const GSTL::String &title);
    };

    Application* createApplication();
}