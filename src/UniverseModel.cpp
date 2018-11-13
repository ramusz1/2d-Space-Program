#include "UniverseModel.hpp"
#include "models/Triangle.hpp"
#include <iostream>

UniverseModel::UniverseModel()
{
    Triangle triangle(0.5);
    worldObjects.push_back(move(triangle));
}

const vector<Drawable>& UniverseModel::getWorldObjects() const
{
    return worldObjects;
}