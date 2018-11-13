#include "Triangle.hpp"

using namespace std;

const vector<float> Triangle::baseVertices = { 
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
    };

Triangle::Triangle(const float scale)
{
    vertices = Triangle::baseVertices;
    for(auto& x : vertices)
    {
        x *= scale;
    }
    bufferVertices(vertices);
}