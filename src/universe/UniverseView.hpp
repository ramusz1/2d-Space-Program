#pragma once
#include "window/Window.hpp"
#include "UniverseModel.hpp"

class UniverseView
{
private:
    const Window& window;
    const UniverseModel& universeModel;
    GLuint programId;
    GLuint positionLocation;
    GLuint colorLocation;
public:
    UniverseView(const Window& window, const UniverseModel&);
    void render();
};