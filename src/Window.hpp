#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <exception>

using namespace std;

class WindowException : public exception
{
public:
    WindowException(const char* msg);
    const char* what() const noexcept;
private:
    const char* message;
};

class Window
{
public:
    bool isOpen();
    void swapBuffers() const;
    Window();
    ~Window();
private :
    GLFWwindow* window;
};