#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include "../../utils/headers/point.hpp"
#include "../../utils/headers/point2d.hpp"
#include "../../utils/headers/utils.hpp"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

class Primitive {
    private:
        vector<Point> points, normals;
        vector<Point2D> textures;
    
    public:
        vector<Point> const &getPoints() const {return points;}
        vector<Point> const &getNormals() const {return normals;}
        vector<Point2D> const &getTextures() const {return textures;}

        void setPoints(vector<Point> const &p) {points = p;}
        void setNormals(vector<Point> const &n) {normals = n;}
        void setTextures(vector<Point2D> const &t) {textures = t;}

        void addPoint(Point p) {points.push_back(p);}
        void addNormal(Point n) {normals.push_back(n);}
        void addTexture(Point2D t) {textures.push_back(t);}

        virtual void point_generator() = 0;

        Primitive() {
            this->points = vector<Point>();
            this->normals = vector<Point>();
            this->textures = vector<Point2D>();
        }

        Primitive(vector<Point> points, vector<Point> normals, vector<Point2D> textures) {
            this->points = points;
            this->normals = normals;
            this->textures = textures;
        }
};

#endif