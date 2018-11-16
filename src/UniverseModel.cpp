#include <iostream>

#include "UniverseModel.hpp"
#include "models/Triangle.hpp"
#include "models/Square.hpp"

using namespace std;

UniverseModel::UniverseModel()
{
    worldObjects.push_back(make_unique<Triangle>(0.5));
    worldObjects.push_back(make_unique<Square>(0.5));
}

const vector< unique_ptr<Drawable> >& UniverseModel::getWorldObjects() const
{
    return worldObjects;
}