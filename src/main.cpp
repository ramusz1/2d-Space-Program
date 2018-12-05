#include <iostream>
#include <chrono>
#include <thread>

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
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            window.pollEvents();
            universeModel.update();
        }
    } catch(WindowException &e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}