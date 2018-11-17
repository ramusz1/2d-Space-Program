#include "UniverseController.hpp"

UniverseController::UniverseController(const UniverseModel& universeModel):
    universeModel(universeModel)
{}

void UniverseController::eventHandler(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        quit();
}

void UniverseController::quit()
{
    isGameRunningFlag = false;
}

bool UniverseController::isGameRunning()
{
    return isGameRunningFlag;
}