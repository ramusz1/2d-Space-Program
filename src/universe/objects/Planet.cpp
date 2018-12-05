#include <memory>

#include "Planet.hpp"
#include "universe/shapes/Circle.hpp"


Planet::Planet(double mass, glm::dvec2 position, double radius):
    PhysicalObject("Planet")
{
    shape = make_shared<Circle>(radius);
    this->mass = mass;
}