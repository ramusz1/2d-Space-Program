#include "PhysicalObject.hpp"

#include <iostream>

using namespace std;

PhysicalObject::PhysicalObject(string debugName):
    debugName(debugName),
    forceCalculator(debugName)
{}

PhysicalObject::PhysicalObject(string debugName, shared_ptr<Shape> shape, double mass):
    debugName(debugName),
    forceCalculator(debugName),
    shape(shape),
    mass(mass)
{}

shared_ptr<Shape> PhysicalObject::getShape()
{
    //update shape position and orientation
    shape->setPosition(position);
    return shape;
}

void PhysicalObject::update(double dt)
{
    auto velocity = momentum / mass;
    auto angularVelocity = angularMomentum / momentOfInertia;

    auto force = forceCalculator.getNetForce();
    // vector operation?
    position += dt * velocity;
    orientation += dt * angularVelocity;
    momentum += dt * force;
    angularMomentum += dt * torque;
}

void PhysicalObject::applyForce(glm::dvec4 force)
{
    // TODO, replace the functions below with this one
    // offset = force[0], force[1]  - position 
}

int PhysicalObject::applyForce(glm::dvec2 force)
{
    return forceCalculator.addForce(force);
}

void PhysicalObject::removeForce(int id)
{
    forceCalculator.removeForce(id);
}

void PhysicalObject::applyTempForce(const glm::dvec2& force)
{
    forceCalculator.addTempForce(force);
}

void PhysicalObject::removeTempForces()
{
    forceCalculator.removeTempForces();
}

void PhysicalObject::applyTorque(double torque)
{
    this->torque += torque;
}