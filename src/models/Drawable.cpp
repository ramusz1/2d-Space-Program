#include <cassert>

#include "Drawable.hpp"

using namespace std;

Drawable::Drawable() :
    isInvalid(false)
{
    glGenBuffers(1, &vertexBuffer);
}

Drawable::Drawable(Drawable&& drawable) : 
    vertexBuffer(drawable.vertexBuffer),
    isInvalid(false)
{
    drawable.invalidate();
}

void Drawable::invalidate()
{
    isInvalid = true;
}

void Drawable::bufferVertices(const vector<float>& vertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    int size = vertices.size() * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER, size, &(vertices.front()), GL_STATIC_DRAW);
}

GLuint Drawable::getVertexBuffer() const
{
    assert(isInvalid == false);
    return vertexBuffer;
}

Drawable::~Drawable()
{
    if(!isInvalid)
        glDeleteBuffers(1, &vertexBuffer);
}