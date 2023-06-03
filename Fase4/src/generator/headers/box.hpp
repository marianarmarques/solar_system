#ifndef BOX_HPP
#define BOX_HPP

#include "../../generator/headers/primitive.hpp"

class Box : public Primitive {
    private:
        float length;
        int grid;

    public:
        float getLength() const {return length;}
        int getGrid() const {return grid;}

        void point_generator();
        
        Box(float length, int grid) {
            this->length = length;
            this->grid = grid;
        }
};

#endif