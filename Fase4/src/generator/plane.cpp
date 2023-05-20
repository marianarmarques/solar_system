#include "headers/plane.hpp"

map<int, vector<Point>> Plane::point_generator() {

    vector<Point> points;
    vector<Point> normals;

    float size = length / (float) grid;
    float h_size = length / 2.0;
    float px = 0, pz = 0, px2 = 0, pz2 = 0;

    for(int i = 0; i < grid; i++) {
        for(int j = 0; j < grid; j++) {

            px = -h_size + (size * j);      // x à esquerda <- num plano 2D
            pz = h_size - (size * i);       // z a baixo    <- num plano 2D
            px2 = -h_size + (size * (j+1)); // x à direita  <- num plano 2D
            pz2 = h_size - (size * (i+1));  // z a cima     <- num plano 2D

            Point p1 = Point(px, 0, pz2);
            Point p2 = Point(px, 0, pz);
            Point p3 = Point(px2, 0, pz);
            Point p4 = Point(px2, 0, pz2);



            // Face superior do plano
            Point v1 = Point(), v2 = Point(), normal11 = Point(), normal12 = Point(), normal13 = Point(), normal14 = Point();

            v1.subPoints(&p1, &p2);
            v2.subPoints(&p1, &p3);
            normal11.cross(&v1, &v2);
            normal11.normalize();

            v1.subPoints(&p2, &p3);
            v2.subPoints(&p2, &p4);
            normal12.cross(&v1, &v2);
            normal12.normalize();

            v1.subPoints(&p3, &p4);
            v2.subPoints(&p3, &p1);
            normal13.cross(&v1, &v2);
            normal13.normalize();

            v1.subPoints(&p4, &p1);
            v2.subPoints(&p4, &p2);
            normal14.cross(&v1, &v2);
            normal14.normalize();

            // 1st triangle
            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p3);

            normals.push_back(normal11);
            normals.push_back(normal12);
            normals.push_back(normal13);

            // 2nd triangle
            points.push_back(p3);
            points.push_back(p4);
            points.push_back(p1);

            normals.push_back(normal13);
            normals.push_back(normal14);
            normals.push_back(normal11);



            // Face inferior do plano
            points.push_back(p3);
            points.push_back(p2);
            points.push_back(p1);

            normals.push_back(normal13);
            normals.push_back(normal12);
            normals.push_back(normal11);

            points.push_back(p1);
            points.push_back(p4);
            points.push_back(p3);

            normals.push_back(normal11);
            normals.push_back(normal14);
            normals.push_back(normal13);
        }
    }

    return {{0, points}, {1, normals}};
}