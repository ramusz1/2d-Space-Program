#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window/Window.hpp"
#include "window/WindowEventHandler.hpp"
#include "UniverseModel.hpp"

class UniverseController : public WindowEventHandler
{
public:
    UniverseController(UniverseModel& universeModel);
    void eventHandler(int key, int scancode, int action, int mods) override;
    bool isGameRunning();
    void quit();
    void rocketMainEngineOn();
    void rocketMainEngineOff();

private:
    bool isGameRunningFlag = true;
    UniverseModel& universeModel;
    void handleKeyPress(int key);
    void handleKeyRelease(int key);
};