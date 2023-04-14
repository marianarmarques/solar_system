#ifndef SPHERE_HEADER
#define SPHERE_HEADER

#include "point.hpp"
#include "primitive.hpp"
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;

class Sphere : public Primitive {
    private:
        float radius;
        int slices;
        int stacks;

    public:
        float getRadius() const {return radius;}
        int getSlices() const {return slices;}
        int getStacks() const {return stacks;}

        vector<Point> point_generator();
        
        Sphere(float radius, int slices, int stacks) {
            this->radius = radius;
            this->slices = slices;
            this->stacks = stacks;
        }
};

#endif