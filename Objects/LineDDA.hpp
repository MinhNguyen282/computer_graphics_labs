#ifndef LINE_DDA_HPP
#define LINE_DDA_HPP
#include "DrawableObject.hpp"

class LineDDA : public DrawableObject {
    public:
        LineDDA();
        LineDDA(int x1, int y1, int x2, int y2);
        void draw() override;
    private:
        int x1, y1, x2, y2;
};

#endif