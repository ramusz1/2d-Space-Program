#pragma once

#include <GL/glew.h>
#include "glm/glm.hpp"

#include <vector>

using namespace std;


/** 
* Manages vertex buffer
**/
class Drawable
{
public:
    static const unsigned int dimensions;

    Drawable(GLenum, glm::vec3 color);
    Drawable(const Drawable& drawable) = delete;
    GLenum getMode() const;
    GLuint getVertexBuffer() const;
    unsigned int getVerticesCount() const;
    const float* getColor() const;

    void bufferVertices(const vector<float>&);
    ~Drawable();

private:
    GLenum mode;
    GLuint vertexBuffer;
    unsigned int verticesCount = 0;
    glm::vec3 color;
};