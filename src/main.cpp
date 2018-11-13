#include <iostream>
#include <unistd.h> // usleep 

#include "Window.hpp"
#include "UniverseView.hpp"
#include "UniverseModel.hpp"

int main(){

    try{
        Window window;
        UniverseModel universeModel;
        UniverseView universeView(window, universeModel);

        while(window.isOpen())
        {
            universeView.render();
            usleep(10000);
        }
    } catch(WindowException &e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    /*
    glfwSetKeyCallback(window, universeController.eventHandler)
    */
    return 0;
}