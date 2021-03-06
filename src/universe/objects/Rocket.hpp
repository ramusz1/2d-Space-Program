#pragma once

#include "universe/physics/PhysicalObject.hpp"

class Rocket : public PhysicalObject
{
private:
    int mainEngineForceId = -1;

public:
    Rocket(glm::dvec2);

    void mainEngineOn();
    void mainEngineOff();
    void rotate(int direction);
};