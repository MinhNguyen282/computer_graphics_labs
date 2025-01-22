#include <GL/glut.h>
#include "Objects/DrawableObject.hpp"
#include "Objects/LineDDA.hpp"
#include "Objects/LineBresenham.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void display();
void init();
std::vector<DrawableObject*> objects;
void parseInputFile(const std::string& filename);

int main(int argc, char** argv) {
    parseInputFile("input.txt");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawing Objects");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    // Cleanup
    for (auto obj : objects) {
        delete obj;
    }

    return 0;
}

void parseInputFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening input file!\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        int objType;
        iss >> objType;

        switch (objType) {
            case LINE_DDA: {
                int x1, y1, x2, y2;
                iss >> x1 >> y1 >> x2 >> y2;
                // Create LineDDA object and add to objects vector
                objects.push_back(new LineDDA(x1, y1, x2, y2));
                break;
            }
            case LINE_BRESENHAM: {
                int x1, y1, x2, y2;
                iss >> x1 >> y1 >> x2 >> y2;
                // Create LineBresenham object and add to objects vector
                objects.push_back(new LineBresenham(x1, y1, x2, y2));
                break;
            }
            case CIRCLE_MIDPOINT: {
                int xt, yt, rt;
                iss >> xt >> yt >> rt;
                // Create CircleMidpoint object and add to objects vector
                break;
            }
            case ELLIPSE_MIDPOINT: {
                int xt, yt, a, b;
                iss >> xt >> yt >> a >> b;
                // Create EllipseMidpoint object and add to objects vector
                break;
            }
            case PARABOLA_MIDPOINT: {
                int xt, yt, p;
                iss >> xt >> yt >> p;
                // Create ParabolaMidpoint object and add to objects vector
                break;
            }
            case HYPERBOLA_MIDPOINT: {
                int xt, yt, a, b;
                iss >> xt >> yt >> a >> b;
                // Create HyperbolaMidpoint object and add to objects vector
                break;
            }
            default:
                std::cerr << "Unknown object type: " << objType << "\n";
                break;
        }
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glColor3f(0.0, 0.0, 0.0); // Black drawing color
    glPointSize(1.0);
    gluOrtho2D(0, 640, 0, 480);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    clock_t start_time = clock();

    // Draw all objects
    for (auto obj : objects) {

        obj->draw();

    }
    glFlush();
    clock_t end_time = clock();
    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000; // in milliseconds
    std::cout << "Execution time: " << execution_time << " ms" << std::endl;
}