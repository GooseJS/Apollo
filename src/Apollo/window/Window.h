#pragma once

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <gstl/collections/String.h>

#include "Events.h"
#include "Apollo/Logger.h"


namespace Apollo
{
    class Window
    {
    private:
        GLFWwindow* _window;
        Window();
    public:
        void createWindow(int width, int height, GSTL::String title);
        bool shouldClose();

        void update();
        void swapBuffers();

        operator GLFWwindow*(){ return _window; }

        ~Window();

        static Window& getInstance()
        {
            static Window window;
            return window;
        }
    };
}