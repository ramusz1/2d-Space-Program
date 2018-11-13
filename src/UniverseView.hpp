#pragma once
#include "Window.hpp"
#include "UniverseModel.hpp"

class UniverseView
{
private:
    const Window& window;
    GLuint programId;
    const UniverseModel& universeModel;
public:
    UniverseView(const Window& window, const UniverseModel&);
    void render();
};