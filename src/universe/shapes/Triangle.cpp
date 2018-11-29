#include <iostream>

#include <GL/glew.h>
#include "glm/glm.hpp"

#include "Triangle.hpp"

using namespace std;
using namespace glm;

const vector<vec3> Triangle::baseVertices = { 
        vec3(-1, -1, 0),
        vec3(1, -1, 0),
        vec3(0,  1, 0),
    };

Triangle::Triangle(const float scale) :
    Shape(GL_TRIANGLES),
    vertices(Triangle::baseVertices)
{
    for(auto& vertex : vertices)
    {
        vertex *= scale;
    }
    bufferVertices(vertices);
}

void Triangle::bufferVertices(const vector<vec3>& verticesCopy)
{
    // nasty
    // copy vertices to flat vector<float> 
    vector<float> buffer;
    buffer.reserve(dimensions * verticesCopy.size());
    for(auto& vertex : verticesCopy)
    {
        for(int i = 0; i < dimensions; ++i)
            buffer.push_back(vertex[i]);
    }
    Drawable::bufferVertices(buffer);
}

void Triangle::setPosition(glm::dvec2 position){
    vec2 positionAsFloat = position;
    vec3 expandedPositionAsFloat(positionAsFloat, 0.0f);
    vector<vec3> copy(vertices);
    for(auto& vertex : copy)
        vertex += expandedPositionAsFloat;

    bufferVertices(copy);
};

void Triangle::setOrientation(glm::dvec2 position){};