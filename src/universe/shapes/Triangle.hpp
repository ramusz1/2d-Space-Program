#pragma once

#include "Shape.hpp"

#include "glm/glm.hpp"

#include <vector>
using namespace std;

class Triangle: public Shape
{
private:
    static const vector<glm::vec3> triangleVertices;

public:
    Triangle(glm::vec3 color, const float scale);
};