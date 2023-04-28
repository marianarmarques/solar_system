#ifndef CONE_HPP
#define CONE_HPP

#include "point.hpp"
#include "primitive.hpp"
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;

class Cone : public Primitive {
    private:
        float radius, height;
        int slices, stacks;

    public:
        float getRadius() const {return radius;}
        float getHeight() const {return height;}
        int getSlices() const {return slices;}
        int getStacks() const {return stacks;}

        vector<Point> point_generator();

        Cone(float radius, float height, int slices, int stacks) {
            this->radius = radius;
            this->height = height;
            this->slices = slices;
            this->stacks = stacks;
        }
};

#endif