#include "Window.hpp"

using namespace std;

WindowException::WindowException(const char* msg) : message(msg){}

const char* WindowException::what() const noexcept{
    return message;
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(window);
}

bool Window::isOpen(){
    glfwPollEvents();
    return glfwWindowShouldClose(window) == 0;
}

Window::Window(){
   // initialize glfw
    if( !glfwInit() )
    {
        throw WindowException("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1024, 768, "KERSQUAR", NULL, NULL);
    if( window == NULL){
        glfwTerminate();
        throw WindowException("Failed to open GLFW window"); 
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        throw WindowException("Failed to initialize GLEW");
    }
}

Window::~Window()
{
    glfwTerminate();
}
