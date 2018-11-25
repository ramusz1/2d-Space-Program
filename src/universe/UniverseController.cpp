#include "UniverseController.hpp"

#include <iostream>

UniverseController::UniverseController(UniverseModel& universeModel):
    universeModel(universeModel)
{}

void UniverseController::eventHandler(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        quit();
    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        liftoff();
}   

void UniverseController::quit()
{
    isGameRunningFlag = false;
}

void UniverseController::liftoff()
{
    std::cerr << "LIFT OFF! \n";
    auto rocket = universeModel.getRocket();
    rocket->thrust();
}

bool UniverseController::isGameRunning()
{
    return isGameRunningFlag;
}