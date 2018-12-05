#include <set>
#include <vector>

#include "glm/glm.hpp"

class ForceCalculator
{
public:
    ForceCalculator(std::string debugName);
    int addForce(const glm::dvec2& force);
    void addTempForce(const glm::dvec2& force);
    void removeForce(int id);
    void removeTempForces();
    glm::dvec2 getNetForce();

private:
    std::string debugName;

    std::set< int > identifiers;
    std::set< std::pair<double, int> > forcesX;
    std::set< std::pair<double, int> > forcesY;

    std::vector< double> tempForcesX;
    std::vector< double> tempForcesY;

    int getNewId();
    void removeId(int id);
    double getNetForceInOneDirection(std::set< std::pair<double, int> >&, std::vector<double>&);
};
