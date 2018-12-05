#include <iostream>

#include <GL/glew.h>
#include "glm/glm.hpp"

#include "Shape.hpp"

using namespace std;
using namespace glm;

Shape::Shape(GLenum mode, vector<vec3> vertices, float scale):
    Drawable(mode),
    baseVertices(vertices),
    position(0.0,0.0)
{
    for(auto& vertex : baseVertices)
    {
        vertex *= scale;
    }
    currentVertices = baseVertices;
    bufferVertices();
}

void Shape::bufferVertices()
{
    // copy vertices to flat vector<float>
    vector<float> buffer;
    buffer.reserve(dimensions * currentVertices.size());
    for(auto& vertex : currentVertices)
    {
        for(int i = 0; i < dimensions; ++i)
            buffer.push_back(vertex[i]);
    }
    Drawable::bufferVertices(buffer);
}

void Shape::setPosition(glm::dvec2 position){
    this->position = position;
    vec2 positionAsFloat = position;
    vec3 expandedPositionAsFloat(positionAsFloat, 0.0f);
    currentVertices = baseVertices;
    for(auto& vertex : currentVertices)
        vertex += expandedPositionAsFloat;

    bufferVertices();
};

void Shape::setOrientation(glm::dvec2 orientation){};