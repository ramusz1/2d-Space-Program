#include <memory>

#include "glm/glm.hpp"

#include "Rocket.hpp"
#include "universe/shapes/Triangle.hpp"


Rocket::Rocket(glm::dvec2 position):
    PhysicalObject("Rocket")
{
    double scale = 0.03;
    this->position = position;
    shape = make_shared<Triangle>(glm::vec3(1, 1, 1), scale);
    mass = 1;
}

void Rocket::mainEngineOn()
{
    glm::vec2 thrustDirection(0, 1);
    float scalar = 0.15f;
    auto force = scalar * thrustDirection;
    mainEngineForceId = applyForce(force);
}

void Rocket::mainEngineOff()
{
    removeForce(mainEngineForceId);
    mainEngineForceId = -1;
}

void Rocket::rotate(int direction)
{
    double scalar = 0.0001f;
    int sign = direction > 0 ? 1 : -1;
    applyTorque(scalar * direction);
}