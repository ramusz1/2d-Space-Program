#include "PhysicsEngine.hpp"


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

    // gravity situation and forces in general are hopeles
    // TODO FIX IT ALL

    // add gravity
    dvec2 gravity(0,-0.001f);
    vector<int> gravityIdentifiers;
    gravityIdentifiers.reserve(input.size());
    for(auto& physicalObject : input)
    {
        auto id = physicalObject->applyForce(gravity);
        gravityIdentifiers.push_back(id);
    }

    for(auto& physicalObject : input)
    {
        physicalObject->update(deltaTime);
    }

    // remove gravity
    auto gravityIdIter = gravityIdentifiers.begin();
    for(auto& physicalObject : input)
    {
        physicalObject->removeForce(*gravityIdIter);
        ++gravityIdIter;
    }

}

void PhysicsEngine::predictTrajectory()
{
    /* Predicts trajectory of an object assuming it will be only affected by gravity 
    * ( and collisions with planets .. )
    * TODO
    * return some drawable arc
    */
}

