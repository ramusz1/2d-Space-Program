#include "PhysicsEngine.hpp"

#include <iostream>

PhysicsEngine::PhysicsEngine(double deltaTime):
    deltaTime(deltaTime)
{}

// inplace? 
void PhysicsEngine::simulate(std::vector<shared_ptr<PhysicalObject> >& input)
{
    /*
    1. get all forces - some outside ones might appear 
        - controller sets forces like engines and stuff, soooo .. done?
    2. get gravity
        - second milestone? xd
    3. update objects
        - hmm xd
    FIRST MILESTONE
    4. check for collisions
        if occured then binary search when exactly occured
    5. apply contact forces
    5.5. include collisions in updating objects
    6. PROFIT
    */

    // add gravity
    for(int i = 0; i < input.size(); ++i)
    {
        for(int j = i + 1; j < input.size(); ++j)
        {
            applyGravityToObjects(input[i], input[j]);
        }
    }
    
    // update objects
    for(auto& physicalObject : input)
    {
        physicalObject->update(deltaTime);
    }

    // remove gravity
    for(auto& physicalObject : input)
    {
        physicalObject->removeTempForces();
    }

}

void PhysicsEngine::applyGravityToObjects(shared_ptr<PhysicalObject>& a, shared_ptr<PhysicalObject>& b)
{
    auto differenceInPosition = a->position - b->position;
    auto distance = glm::length(differenceInPosition);
    auto forceValue = const_G * a->mass * b->mass / (distance * distance);
    auto force = forceValue * (differenceInPosition / distance);
    // std::cerr << forceValue << std::endl;
    a->applyTempForce(-force);
    b->applyTempForce(force);
}

void PhysicsEngine::predictTrajectory()
{
    /* Predicts trajectory of an object assuming it will be only affected by gravity 
    * ( and collisions with planets .. )
    * TODO
    * return some drawable arc
    */
}

