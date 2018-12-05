#pragma once

#include <vector>

#include "PhysicalObject.hpp"

class PhysicsEngine
{
public:
    PhysicsEngine(double deltaTime);

    void simulate(std::vector<shared_ptr<PhysicalObject> >& input);

    void predictTrajectory();

private:
    double deltaTime;
    void applyGravityToObjects(shared_ptr<PhysicalObject>& a, shared_ptr<PhysicalObject>& b);
    double const_G = 6.67408e-11; // -11 is the real deal
};