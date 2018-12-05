#pragma once

#include "glm/glm.hpp"

#include <vector>

#include "Drawable.hpp"

class Shape : public Drawable
{
public:
    Shape(GLenum mode, std::vector<glm::vec3> vertices, float scale);
    virtual void setPosition(glm::dvec2);
    virtual void setOrientation(glm::dvec2);

protected:
    std::vector<glm::vec3> baseVertices;
    std::vector<glm::vec3> currentVertices;
    glm::dvec2 position;

    void bufferVertices();

};