#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include "../../utils/headers/point.hpp"
#include <vector>

class Primitive {
    private:
        vector<Point> points;
    
    public:
        vector<Point> const &getPoints() const {return points;}
        void setPoints(vector<Point> const &p) {points = p;}

        virtual vector<Point> point_generator() = 0;
};

#endif