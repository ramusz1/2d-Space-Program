#include "PhysicalObject.hpp"

#include <iostream>

using namespace std;

PhysicalObject::PhysicalObject(shared_ptr<Shape> shape, double mass):
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
    std::cerr << "velocity: " << velocity[0] << ' ' << velocity[1] << std::endl;
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

void PhysicalObject::applyTorque(double torque)
{
    this->torque += torque;
}