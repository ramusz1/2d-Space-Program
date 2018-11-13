#pragma once

#include "Drawable.hpp"

#include <vector>
using namespace std;

class Triangle: public Drawable
{
private:
    static const vector<float> baseVertices;

    vector<float> vertices;

public:
    Triangle(float scale);
    // void move(); TODO
    // void rotate();
};