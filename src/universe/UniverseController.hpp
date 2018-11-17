#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window/Window.hpp"
#include "window/WindowEventHandler.hpp"
#include "UniverseModel.hpp"

class UniverseController : public WindowEventHandler
{
public:
    UniverseController(const UniverseModel& universeModel);
    void eventHandler(int key, int scancode, int action, int mods) override;
    bool isGameRunning();
    void quit();

private:
    bool isGameRunningFlag = true;
    const UniverseModel& universeModel;
};