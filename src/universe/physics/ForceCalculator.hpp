#include <set>
#include <vector>
#include <cstdlib>

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

    struct PairAbsComp
    {
        bool operator() (const std::pair<double, int>&, const std::pair<double, int>&) const;
    };

    std::set< std::pair<double, int>, PairAbsComp> forcesX;
    std::set< std::pair<double, int>, PairAbsComp> forcesY;

    struct AbsComp
    {
        bool operator() (const double& lhs, const double& rhs) const;
    };

    std::vector< double> tempForcesX;
    std::vector< double> tempForcesY;

    int getNewId();
    void removeId(int id);
    double getNetForceInOneDirection(std::set< std::pair<double, int>, PairAbsComp>&, std::vector<double>&);
};
