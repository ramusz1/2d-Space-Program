#include "ForceCalculator.hpp"

#include <algorithm>
#include <numeric>

#include <iostream>

int ForceCalculator::addForce(glm::dvec2 force)
{
    auto id = getNewId();
    auto lambda = [](auto& a, auto& b){return a.first < b.first;};
    forcesX.insert( std::make_pair(force[0],id));
    forcesY.insert( std::make_pair(force[1],id));
    return id;
}

void ForceCalculator::removeForce(int id)
{
    auto lambda = [&id](auto& x){return x.second == id;};
    auto it = std::find_if(forcesX.begin(), forcesX.end(), lambda);
    forcesX.erase(it);
    it = std::find_if(forcesY.begin(), forcesY.end(), lambda);
    forcesY.erase(it);
}

glm::dvec2 ForceCalculator::getNetForce()
{
    auto lambda = [](auto& a, auto& b){ return a + b.first;};
    auto x = std::accumulate(forcesX.begin(), forcesX.end(), 0.0, lambda);
    auto y = std::accumulate(forcesY.begin(), forcesY.end(), 0.0, lambda);
    return glm::dvec2(x,y);
}

int ForceCalculator::getNewId()
{
    int i = 0;
    auto it = std::find_if(identifiers.begin(), identifiers.end(),
            [&i](auto& x){return i++ == x;}
        );
    --i;
    identifiers.insert(it, i);
    return i;
}

void ForceCalculator::removeId(int id)
{
    identifiers.erase(id);
}
