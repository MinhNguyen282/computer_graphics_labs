#ifndef __LINE_BRESENHAM_HPP__
#define __LINE_BRESENHAM_HPP__

#include "DrawableObject.hpp"

class LineBresenham : public DrawableObject {
    public:
        LineBresenham(int x1, int y1, int x2, int y2);
        void draw() override;
    private:
        int x1, y1, x2, y2;
};

#endif