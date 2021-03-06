#pragma once

#include "Shape.hpp"

#include <vector>
using namespace std;

class Circle: public Shape
{
private:
    static const vector<glm::vec3> baseVertices;

public:
    Circle(glm::vec3 color, const float scale);
};