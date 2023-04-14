#ifndef BOX_HEADER
#define BOX_HEADER

#include "point.hpp"
#include "primitive.hpp"

using namespace std;

class Box : public Primitive {
    private:
        float length;
        int grid;

    public:
        float getLength() const {return length;}
        int getGrid() const {return grid;}

        vector<Point> point_generator();
        
        Box(float length, int grid) {
            this->length = length;
            this->grid = grid;
        }
};

#endif