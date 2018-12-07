#include <cassert>
#include <iostream>

#include "glm/ext.hpp"

#include "Drawable.hpp"



using namespace std;

const unsigned int Drawable::dimensions = 3;

Drawable::Drawable(GLenum mode, glm::vec3 color):
    mode(mode),
    color(color)
{
    glGenBuffers(1, &vertexBuffer);
}

void Drawable::bufferVertices(const vector<float>& vertices)
{
    verticesCount = vertices.size() / Drawable::dimensions;
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    int size = vertices.size() * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER, size, &(vertices.front()), GL_STATIC_DRAW);
}

GLenum Drawable::getMode() const
{
    return mode;
}

GLuint Drawable::getVertexBuffer() const
{
    return vertexBuffer;
}

unsigned int Drawable::getVerticesCount() const
{
    return verticesCount;
}

const float* Drawable::getColor() const
{
    return glm::value_ptr(color);
}

Drawable::~Drawable()
{
    glDeleteBuffers(1, &vertexBuffer);
}