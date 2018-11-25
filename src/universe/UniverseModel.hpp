#pragma once

#include <memory>

#include "shapes/Drawable.hpp"
#include "physics/PhysicalObject.hpp"
#include "physics/PhysicsEngine.hpp"
#include "objects/Rocket.hpp"

using namespace std;

class UniverseModel{
private:
    vector< shared_ptr<PhysicalObject> > worldObjects;
    shared_ptr<Rocket> rocket;

    PhysicsEngine physicsEngine;

public:
    UniverseModel();
    const vector<shared_ptr<Drawable> > getDrawables() const;
    shared_ptr<Rocket> getRocket();

    void update();

};