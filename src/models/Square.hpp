#pragma once

#include "Drawable.hpp"

#include <vector>
using namespace std;

class Square: public Drawable
{
private:
    static const vector<float> baseVertices;

    vector<float> vertices;

public:
    Square(float scale);
};