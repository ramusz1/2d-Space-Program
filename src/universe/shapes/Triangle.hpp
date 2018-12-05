#pragma once

#include "Shape.hpp"

#include <vector>
using namespace std;

class Triangle: public Shape
{
private:
    static const vector<glm::vec3> triangleVertices;

public:
    Triangle(float scale);
};