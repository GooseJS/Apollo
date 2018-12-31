#include "Window.h"

namespace Apollo
{
    Window::Window()
    {

    }

    Window::~Window()
    {
        EventWindowClose event;
        EventSystem::getInstance()->dispatchEvent(event);
        if (_window != nullptr) glfwDestroyWindow(_window);
    }

    void Window::createWindow(int width, int height, GSTL::String title)
    {
        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!_window)
        {
            APOLLO_CORE_CRITICAL("Could not create window!");
        }
    }

    bool Window::shouldClose()
    {
        if (_window != nullptr)
            return glfwWindowShouldClose(_window) != 0;
        else
            return true;
    }

    void Window::update()
    {
        glfwPollEvents();
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(_window);
    }

}