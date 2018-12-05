#include "ForceCalculator.hpp"

#include <algorithm>
#include <numeric>

#include <iostream>

#include "MergingTools.hpp"

ForceCalculator::ForceCalculator(std::string debugName):
    debugName(debugName)
{}

int ForceCalculator::addForce(const glm::dvec2& force)
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

void ForceCalculator::addTempForce(const glm::dvec2& force)
{
    tempForcesX.push_back( force[0]);
    tempForcesY.push_back( force[1]);
}

void ForceCalculator::removeTempForces()
{
    tempForcesX.clear();
    tempForcesY.clear();   
}

glm::dvec2 ForceCalculator::getNetForce()
{
    /*
    for(auto& f : forcesY)
        std::cerr << debugName << " force: " << f.first << std::endl;
    */
    auto x = getNetForceInOneDirection(forcesX, tempForcesX);
    auto y = getNetForceInOneDirection(forcesY, tempForcesY);
    // std::cerr << debugName << " Net forceY " << y << std::endl;
    return glm::dvec2(x, y);
}

double ForceCalculator::getNetForceInOneDirection(std::set< std::pair<double, int> >& forces, std::vector<double>& tempForces)
{
    std::sort(tempForces.begin(), tempForces.end());
    SetOfPairsView viewBegin(forces.begin());
    SetOfPairsView viewEnd(forces.end());
    Accumulator output;
    std::back_insert_iterator< Accumulator > adder(output);
    std::merge(viewBegin, viewEnd, tempForces.begin(), tempForces.end(), adder);
    return output.getValue();
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
