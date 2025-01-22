#include "LineDDA.hpp"
#include "GL/glut.h"

LineDDA::LineDDA() {
    std::cout << "LineDDA constructor\n";
}

LineDDA::LineDDA(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
    std::cout << "LineDDA constructor\n";
}

void LineDDA::draw() {
    std::cout << "Drawing LineDDA\n";
    // Implement DDA algorithm here
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    for(int i=0; i<=steps; i++) {
        glVertex2i(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
}