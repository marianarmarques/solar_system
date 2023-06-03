#ifndef BEZIER_HPP
#define BEZIER_HPP

#include "../../generator/headers/primitive.hpp"

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
        
        Point getBezierPoint(int p, float u, float v, int flag);
        
        void point_generator();

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