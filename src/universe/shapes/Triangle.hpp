#pragma once

#include "Shape.hpp"

#include <vector>
using namespace std;

class Triangle: public Shape
{
private:
    static const vector<glm::vec3> baseVertices;

    vector<glm::vec3> vertices;

public:
    Triangle(float scale);
    void bufferVertices(const vector<glm::vec3>&);
    void setPosition(glm::dvec2) override;
    void setOrientation(glm::dvec2) override;
};