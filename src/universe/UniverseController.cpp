#include "UniverseController.hpp"

#include <iostream>

UniverseController::UniverseController(UniverseModel& universeModel):
    universeModel(universeModel)
{}

void UniverseController::eventHandler(int key, int scancode, int action, int mods)
{
    if(GLFW_PRESS == action)
    {
        handleKeyPress(key);
    }
    else if (GLFW_RELEASE == action)
    {
        handleKeyRelease(key);
    }
}   

void UniverseController::handleKeyPress(int key)
{
    if (GLFW_KEY_ESCAPE == key)
        quit();
    else if (GLFW_KEY_SPACE == key)
        rocketMainEngineOn();
}

void UniverseController::quit()
{
    isGameRunningFlag = false;
}

void UniverseController::rocketMainEngineOn()
{
    auto rocket = universeModel.getRocket();
    rocket->mainEngineOn();
}

void UniverseController::handleKeyRelease(int key)
{
    if (key == GLFW_KEY_SPACE)
        rocketMainEngineOff();
}

void UniverseController::rocketMainEngineOff()
{
    auto rocket = universeModel.getRocket();
    rocket->mainEngineOff();
}

bool UniverseController::isGameRunning()
{
    return isGameRunningFlag;
}