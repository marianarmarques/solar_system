#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "../../generator/headers/primitive.hpp"
#include <cmath>

class Sphere : public Primitive {
    private:
        float radius;
        int slices;
        int stacks;

    public:
        float getRadius() const {return radius;}
        int getSlices() const {return slices;}
        int getStacks() const {return stacks;}

        map<int, vector<Point>> point_generator();
        
        Sphere(float radius, int slices, int stacks) {
            this->radius = radius;
            this->slices = slices;
            this->stacks = stacks;
        }
};

#endif