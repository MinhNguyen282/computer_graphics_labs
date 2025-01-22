#include "LineBresenham.hpp"
#include "GL/glut.h"

LineBresenham::LineBresenham(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
    if (x1 > x2){
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    std::cout << "LineBensenham constructor\n";
}

void LineBresenham::draw(){
    std::cout << "Drawing LineBensenham\n";
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    int x_inc = x1 < x2 ? 1 : -1;
    int y_inc = y1 < y2 ? 1 : -1;

    glBegin(GL_POINTS);
    if (dx > dy){
        int p = 2 * dy - dx;
        int Const1 = 2 * dy;
        int Const2 = 2 * (dy - dx);
        for(int i=0; i<=dx; i++){
            glVertex2i(x, y);
            x += x_inc;
            if (p < 0){
                p += Const1;
            } else {
                y += y_inc;
                p += Const2;
            }
        }
    }
    else{
        int p = 2 * dx - dy;
        int Const1 = 2 * dx;
        int Const2 = 2 * (dx - dy);
        for(int i=0; i<=dy; i++){
            glVertex2i(x, y);
            y += y_inc;
            if (p < 0){
                p += Const1;
            } else {
                x += x_inc;
                p += Const2;
            }
        }
    }
    glEnd();
}