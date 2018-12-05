#pragma once

#include "glm/glm.hpp"

#include "universe/physics/PhysicalObject.hpp"

class Planet : public PhysicalObject
{

public:
    Planet(double mass, glm::dvec2 position, double radius);
};