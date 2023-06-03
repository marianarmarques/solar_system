#include "headers/plane.hpp"

void Plane::point_generator() {

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
            // 1st triangle
            addPoint(p1);
            addPoint(p2);
            addPoint(p3);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(Point2D(0, 0));
            addTexture(Point2D(0, 1));
            addTexture(Point2D(1, 1));

            // 2nd triangle
            addPoint(p3);
            addPoint(p4);
            addPoint(p1);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(Point2D(1, 1));
            addTexture(Point2D(1, 0));
            addTexture(Point2D(0, 0));

            // Face inferior do plano
            // 1st triangle
            addPoint(p3);
            addPoint(p2);
            addPoint(p1);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(Point2D(0, 0));
            addTexture(Point2D(0, 1));
            addTexture(Point2D(1, 1));

            // 2nd triangle
            addPoint(p1);
            addPoint(p4);
            addPoint(p3);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(Point2D(1, 1));
            addTexture(Point2D(1, 0));
            addTexture(Point2D(0, 0));
        }
    }
}