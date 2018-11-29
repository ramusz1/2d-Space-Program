#pragma once

#include "glm/glm.hpp"

#include "Drawable.hpp"

class Shape : public Drawable
{
public:
    Shape(GLenum mode) : Drawable(mode){};
    virtual void setPosition(glm::dvec2) = 0;
    virtual void setOrientation(glm::dvec2) = 0;
};