#include <iostream>
#include <unistd.h> // usleep 

#include "window/Window.hpp"
#include "universe/UniverseView.hpp"
#include "universe/UniverseModel.hpp"
#include "universe/UniverseController.hpp"

int main(){

    try{
        Window window;
        UniverseModel universeModel;
        UniverseView universeView(window, universeModel);
        UniverseController universeController(universeModel);
        window.setKeyCallback(&universeController);

        while(window.isOpen() and universeController.isGameRunning())
        {
            universeView.render();
            usleep(10000);
            window.pollEvents();
        }
    } catch(WindowException &e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}