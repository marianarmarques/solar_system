#ifndef TORUS_HPP
#define TORUS_HPP

#include "../../generator/headers/primitive.hpp"

class Torus : public Primitive {
    private:
        float radius;
        float ringRadius;
        int slices;
        int stacks;

    public:
        float getRadius() const {return radius;}
        float getRingRadius() const {return ringRadius;}
        int getSlices() const {return slices;}
        int getStacks() const {return stacks;}

        void point_generator();

        Torus(float radius, float ringRadius, int slices, int stacks) {
            this->radius = radius;
            this->ringRadius = ringRadius;
            this->slices = slices;
            this->stacks = stacks;
        }
};

#endif
