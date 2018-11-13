#pragma once

#include <GL/glew.h>

#include <vector>
using namespace std;

class Drawable
{
public:
    Drawable();
    Drawable(Drawable&& drawable);
    GLuint getVertexBuffer() const;
    void bufferVertices(const vector<float>&);
    ~Drawable();
private:
    GLuint vertexBuffer;
    bool isInvalid;
    void invalidate();
};