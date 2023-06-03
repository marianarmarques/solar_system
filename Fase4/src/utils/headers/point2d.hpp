#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>

class Point2D {
    private:
        float x, y;

    public:
        float getX() const {return x;}
        float getY() const {return y;}

        void printPoint() {
            cout << "x:" << x << ", " << y << "y:" << endl;
        }

        Point2D(){
            x = 0;
            y = 0;
        }

        Point2D(float x, float y) {
            this->x = x;
            this->y = y;
        }
};

#endif