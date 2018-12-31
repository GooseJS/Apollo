#include "Application.h"

#include "Apollo/Logger.h"
#include "Apollo/input/InputEvents.h"
#include "Apollo/window/Window.h"

namespace Apollo
{
    static void glfwError(int id, const char* description)
    {
        std::cout << description << std::endl;
    }

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        EventKeyboard event(key, scancode, action, mods);
        EventSystem::getInstance()->dispatchEvent(event);
        if (action == GLFW_PRESS)
        {
            EventKeyPressed pressedEvent(key, scancode, mods);
            EventSystem::getInstance()->dispatchEvent(pressedEvent);
        }
        else if (action == GLFW_RELEASE)
        {
            EventKeyReleased releaseEvent(key, scancode, mods);
            EventSystem::getInstance()->dispatchEvent(releaseEvent);
        }
    }

    Application::Application()
    {
        Logger::init();

        glfwSetErrorCallback(&glfwError);
        if (!glfwInit())
        {
            // TODO: Erorr handling!
            APOLLO_CORE_CRITICAL("GLFW couldn't be initialized!");
        }
    }

    Application::~Application()
    {

    }

    void Application::run()
    {
        while (!Window::getInstance().shouldClose())
        {
            Window::getInstance().update();
            onUpdate();
            onRender();
            Window::getInstance().swapBuffers();
        }
    }

    void Application::createWindow(int width, int height, const GSTL::String &title)
    {
        EventWindowOpen event;
        EventSystem::getInstance()->dispatchEvent(event);
        if (event.cancelled())
            return;

        Window::getInstance().createWindow(width, height, title);
        if (!Window::getInstance())
        {
            // TODO: Error handling!
            APOLLO_CORE_CRITICAL("GLFW Window could not be created!");
        }

        glfwMakeContextCurrent(Window::getInstance());

        if (gl3wInit())
            APOLLO_CORE_CRITICAL("Couldn't initialize OpenGL!");
        if (!gl3wIsSupported(4, 5))
            APOLLO_CORE_CRITICAL("OpenGL 3.2 not supported");

        EventWindowOpened openedEvent;
        EventSystem::getInstance()->dispatchEvent(openedEvent);

        glfwSetKeyCallback(Window::getInstance(), &keyCallback);
    }
}
