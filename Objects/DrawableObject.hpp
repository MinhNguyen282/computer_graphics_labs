#ifndef __DRAWABLE_OBJECT_H
#define __DRAWABLE_OBJECT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Define object types
enum ObjectType {
    LINE_DDA = 0,
    LINE_BRESENHAM = 1,
    CIRCLE_MIDPOINT = 2,
    ELLIPSE_MIDPOINT = 3,
    PARABOLA_MIDPOINT = 4,
    HYPERBOLA_MIDPOINT = 5
};

// Base class for drawable objects
class DrawableObject {
public:
    virtual void draw() = 0;
};

#endif