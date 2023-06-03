#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Point {
    private:
        float x, y, z;
    
    public:
        float getX() const {return x;}
        float getY() const {return y;}
        float getZ() const {return z;}
        
        void setX(float x) {this->x = x;}
        void setY(float y) {this->y = y;}
        void setZ(float z) {this->z = z;}

        float* pointToVector() {
            return new float[3]{x, y, z};
        }
        
        string toString() {
            ostringstream point;                // Criação da stream
            point << x << ' ' << y << ' ' << z; // Preenchimento da stream
            return point.str();                 // Extração do conteúdo da stream
        }

        void subPoints(Point *a, Point *b) {
            x = b->getX() - a->getX();
            y = b->getY() - a->getY();
            z = b->getZ() - a->getZ();
        }

        void cross(Point *a, Point *b) {
            x = a->getY() * b->getZ() - a->getZ() * b->getY();
            y = a->getZ() * b->getX() - a->getX() * b->getZ();
            z = a->getX() * b->getY() - a->getY() * b->getX();

            if(x == 0 && y == 0 && z == 0) {
                x = 0;
                y = -1;
                z = 0;
                /*if(a->isZero()) {
                    a->operator=(Point(0.01, 0.7, 0.01));
                    x = a->getY() * b->getZ() - a->getZ() * b->getY();
                    y = a->getZ() * b->getX() - a->getX() * b->getZ();
                    z = a->getX() * b->getY() - a->getY() * b->getX();
                }
                else {
                    b->operator=(Point(0.01, 0.7, 0.01));
                    x = a->getY() * b->getZ() - a->getZ() * b->getY();
                    y = a->getZ() * b->getX() - a->getX() * b->getZ();
                    z = a->getX() * b->getY() - a->getY() * b->getX();
                }*/
            }
        }

        void normalize() {
            float norm = sqrt(x * x + y * y + z * z);
            x = x / norm;
            y = y / norm;
            z = z / norm;
        }

        void printPoint() {
            cout << "x: " << x << " y: " << y << " z: " << z << endl;
        }

        Point() {
            x = 0;
            y = 0;
            z = 0;
        }

        Point(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

#endif