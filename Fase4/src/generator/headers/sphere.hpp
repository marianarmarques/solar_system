#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "../../generator/headers/primitive.hpp"

class Sphere : public Primitive {
    private:
        float radius;
        int slices;
        int stacks;

    public:
        float getRadius() const {return radius;}
        int getSlices() const {return slices;}
        int getStacks() const {return stacks;}

        void point_generator();
        
        Sphere(float radius, int slices, int stacks) {
            this->radius = radius;
            this->slices = slices;
            this->stacks = stacks;
        }
};

#endif