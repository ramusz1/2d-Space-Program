#include <memory>

#include "glm/glm.hpp"

#include "Rocket.hpp"
#include "universe/shapes/Triangle.hpp"


Rocket::Rocket():
    PhysicalObject()
{
    double scale = 0.1;
    shape = make_shared<Triangle>(scale);
    mass = 1;
}

void Rocket::mainEngineOn()
{
    glm::vec2 thrustDirection(0, 1);
    float scalar = 0.002f;
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