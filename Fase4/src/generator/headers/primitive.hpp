#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include "../../utils/headers/point.hpp"
#include "../../utils/headers/utils.hpp"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Primitive {
    private:
        vector<Point> points, normals;
    
    public:
        vector<Point> const &getPoints() const {return points;}
        vector<Point> const &getNormals() const {return normals;}
        void setPoints(vector<Point> const &p) {points = p;}
        void setNormals(vector<Point> const &n) {normals = n;}

        virtual map<int, vector<Point>> point_generator() = 0;
};

#endif