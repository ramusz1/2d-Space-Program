#include <memory>

#include "Planet.hpp"
#include "universe/shapes/Circle.hpp"


Planet::Planet(double mass, glm::dvec2 position, double radius):
    PhysicalObject("Planet")
{
    shape = make_shared<Circle>(glm::vec3(0.2, 0.7, 0.4), radius);
    this->mass = mass;
}