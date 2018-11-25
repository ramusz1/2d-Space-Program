#include <iostream>
#include <algorithm>

#include "UniverseModel.hpp"
#include "shapes/Triangle.hpp"
#include "shapes/Square.hpp"

using namespace std;

UniverseModel::UniverseModel():
    physicsEngine(0.1)
{
    auto triangle = make_shared<Triangle>(0.5);
    rocket = make_shared<Rocket>();
    worldObjects.push_back(rocket);
    // auto square = make_shared<Square>(0.5);
    // worldObjects.push_back(make_unique<PhysicalObject>(square, 1));
}

const vector< shared_ptr<Drawable> > UniverseModel::getDrawables() const
{
    vector< shared_ptr<Drawable> > drawable(worldObjects.size());
    std::transform(worldObjects.begin(), worldObjects.end(), drawable.begin(),
        [](const auto& obj){ return obj->getShape();});
    return drawable;
}

shared_ptr<Rocket> UniverseModel::getRocket()
{
    return rocket;
}


void UniverseModel::update()
{
    physicsEngine.simulate(worldObjects);
}