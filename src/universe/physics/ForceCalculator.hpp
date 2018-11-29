#include <set>

#include "glm/glm.hpp"

class ForceCalculator
{
public:

    int addForce(glm::dvec2 force);
    void removeForce(int id);
    glm::dvec2 getNetForce();

private:
    std::set< int > identifiers;
    std::set< std::pair<double, int> > forcesX;
    std::set< std::pair<double, int> > forcesY;

    int getNewId();
    void removeId(int id);

};
