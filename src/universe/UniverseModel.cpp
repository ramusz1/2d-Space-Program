#include <iostream>
#include <algorithm>

#include "glm/glm.hpp"

#include "UniverseModel.hpp"
#include "shapes/Triangle.hpp"
#include "shapes/Square.hpp"

#include "objects/Planet.hpp"

using namespace std;

UniverseModel::UniverseModel():
    physicsEngine(0.1)
{
    rocket = make_shared<Rocket>(glm::dvec2(0,0.5));
    worldObjects.push_back(rocket);

    auto planet = make_shared<Planet>(1e8, glm::dvec2(0,0), 0.1);
    worldObjects.push_back(planet);
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