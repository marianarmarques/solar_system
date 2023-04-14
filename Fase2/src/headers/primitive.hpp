#ifndef PRIMITIVE_HEADER
#define PRIMITIVE_HEADER

#include <vector>
#include "point.hpp"

class Primitive {
    private:
        vector<Point> points;
    
    public:
        vector<Point> const &getPoints() const {return points;}
        void setPoints(vector<Point> const &p) {points = p;}

        virtual vector<Point> point_generator() = 0;
};

#endif