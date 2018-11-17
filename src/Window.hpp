#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <exception>
#include <functional>

#include "WindowEventHandler.hpp"

class WindowException : public std::exception
{
public:
    WindowException(const char* msg);
    const char* what() const noexcept override;
private:
    const char* message;
};

class Window
{
public:
    Window();

    bool isOpen();
    void pollEvents();
    void swapBuffers() const;
    void setKeyCallback(WindowEventHandler* eventHandler);
    
    ~Window();
private :
    GLFWwindow* window;
};