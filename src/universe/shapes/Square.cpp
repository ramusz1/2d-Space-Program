#include <GL/glew.h>
#include <iostream>
#include "Square.hpp"

using namespace std;

const vector<float> Square::baseVertices = { 
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,
    };

Square::Square(const float scale) :
    Drawable(GL_TRIANGLES),
    vertices(Square::baseVertices)
{
    for(auto& x : vertices)
    {
        x *= scale;
    }
    bufferVertices(vertices);
}