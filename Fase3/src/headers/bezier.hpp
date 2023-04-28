#ifndef BEZIER_HPP
#define BEZIER_HPP

using namespace std;

#include "point.hpp"
#include "primitive.hpp"
#include "utils.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Bezier : public Primitive {
    private:
        string file;
        int tessellation;
        map<int, vector<Point>> patches;

    public:
        string getFile() const {return file;}
        int getTessellation() const {return tessellation;}
        map<int, vector<Point>> getPatches() const {return patches;}
        
        void parsePatch();
        Point getBezierPoint(int p, float u, float v);
        vector<Point> point_generator();

        Bezier() {
            file = "";
            tessellation = 0;
            patches = map<int, vector<Point>>();
        }

        Bezier(string file, int tessellation) {
            this->file = file;
            this->tessellation = tessellation;
            this->patches = map<int, vector<Point>>();
        }
};

#endif