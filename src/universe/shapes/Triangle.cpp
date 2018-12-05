#include <iostream>

#include <GL/glew.h>
#include "glm/glm.hpp"

#include "Triangle.hpp"

using namespace std;
using namespace glm;

const vector<vec3> Triangle::triangleVertices = { 
        vec3(-1, -1, 0),
        vec3(1, -1, 0),
        vec3(0,  1, 0),
    };

Triangle::Triangle(const float scale):
    Shape(GL_TRIANGLES, Triangle::triangleVertices, scale)
{}