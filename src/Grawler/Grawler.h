#pragma once

#include <Apollo.h>

class Grawler : public Apollo::Application
{
private:
    GLuint _vertexArrayID;
    GLuint _vertexBufferID;
public:
    Grawler() : Application()
    {
        Apollo::Logger::init();
        APOLLO_WARN("What the fuck is up kyle");

        Apollo::EventSystem::getInstance()->addListener<Apollo::EventKeyPressed>(std::bind(&Grawler::onKeyPressed, this, std::placeholders::_1));
        Apollo::EventSystem::getInstance()->addListener<Apollo::EventWindowOpened>(std::bind(&Grawler::onWindowOpen, this, std::placeholders::_1));
        this->createWindow(800, 640, GSTL::String("Fuck me"));
    }

    ~Grawler() override
    {

    }

    GLuint loadShaders(const char* vertexFilePath, const char* fragmentFilePath);

    void onUpdate() override;

    void onRender() override;

    void onKeyPressed(Apollo::IEvent& _event)
    {
        auto &event = dynamic_cast<Apollo::EventKeyPressed&>(_event);
        APOLLO_INFO(glfwGetKeyName(event.key(), event.scancode()));
    }

    void onWindowOpen(Apollo::IEvent &_event);
};