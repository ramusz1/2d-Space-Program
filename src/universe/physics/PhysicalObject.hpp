#pragma once

#include <memory>
#include <string>

#include "glm/glm.hpp"

#include "universe/shapes/Shape.hpp"
#include "universe/shapes/Drawable.hpp"
#include "ForceCalculator.hpp"


using namespace glm;

/* 
* Implemetation of rigid body
*/
class PhysicalObject
{
    /*Based on 
    * http://www.cs.cmu.edu/~baraff/sigcourse/notesd1.pdf
    * equations (2-41 to 2-43)
    */
public:

    std::string debugName;

    // basic physical object

    dvec2 position = dvec2(0,0);
    dvec2 orientation = dvec2(1,0);
    dvec2 momentum = dvec2(0,0);
    double angularMomentum = 0;
    double mass = 1;
    double momentOfInertia = 1;

    double forcesX;
    double forcesY;
    double torqueX;
    double torqueY;

    double torque = 0.0;

    ForceCalculator forceCalculator;
    
    void update(double dt);

    // additional physical data

    void applyForce(dvec4 force); // TODO, replace the functions below with this one
    int applyForce(dvec2 force);
    void removeForce(int id);

    void applyTempForce(const glm::dvec2& force);
    void removeTempForces();

    void applyTorque(double torque);

    void applyGravity(dvec2 force);

    PhysicalObject(std::string);
    PhysicalObject(std::string, shared_ptr<Shape> shape, double mass);

    shared_ptr<Shape> getShape();

protected:

    shared_ptr<Shape> shape;

private:
    bool changed = false;
};