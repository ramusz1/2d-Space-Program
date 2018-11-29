#pragma once

#include <vector>

#include "PhysicalObject.hpp"

class PhysicsEngine
{
public:
    PhysicsEngine(double deltaTime);

    // inplace? 
    void simulate(std::vector<shared_ptr<PhysicalObject> >& input);

    void predictTrajectory();

private:
    double deltaTime;
};