#include "Window.hpp"

WindowException::WindowException(const char* msg) : message(msg){}

const char* WindowException::what() const noexcept{
    return message;
}

bool Window::isOpen(){
    return glfwWindowShouldClose(window) == 0;
}

void Window::pollEvents(){
    glfwPollEvents();
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(window);
}

void Window::setKeyCallback(WindowEventHandler* eventHandler)
{
    glfwSetWindowUserPointer(window, eventHandler);
    auto eventHandlerWrapper = [](GLFWwindow* w, int key, int scancode, int action, int mods)
    {
        static_cast<WindowEventHandler*>(glfwGetWindowUserPointer(w))->eventHandler(key, scancode, action, mods);
    };
    glfwSetKeyCallback(window, eventHandlerWrapper);
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
