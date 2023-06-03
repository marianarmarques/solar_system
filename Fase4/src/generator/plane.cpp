#include "headers/plane.hpp"

void Plane::point_generator() {

    float size = length / (float) grid,
          h_size = length / 2.0,
          div = 1.0f/ grid;

    for(int i = 0; i < grid; i++) {
        for(int j = 0; j < grid; j++) {

            float px = -h_size + (size * j),      // x à esquerda <- num plano 2D
                  pz = h_size - (size * i),       // z a baixo    <- num plano 2D
                  px2 = -h_size + (size * (j+1)), // x à direita  <- num plano 2D
                  pz2 = h_size - (size * (i+1)),  // z a cima     <- num plano 2D
                  div = 1.0f / (float) grid;

            Point p1 = Point(px, 0, pz2),
                  p2 = Point(px, 0, pz),
                  p3 = Point(px2, 0, pz),
                  p4 = Point(px2, 0, pz2);

            Point2D t1 = Point2D(i * div, (j+1) * div),
                    t2 = Point2D(i * div, j * div),
                    t3 = Point2D((i+1) * div, j * div),
                    t4 = Point2D((i+1) * div, (j+1) * div);

            // Face superior do plano
            // 1st triangle
            addPoint(p1);
            addPoint(p2);
            addPoint(p3);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t1);
            addTexture(t2);
            addTexture(t3);

            // 2nd triangle
            addPoint(p3);
            addPoint(p4);
            addPoint(p1);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t3);
            addTexture(t4);
            addTexture(t1);

            // Face inferior do plano
            // 1st triangle
            addPoint(p3);
            addPoint(p2);
            addPoint(p1);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(t3);
            addTexture(t2);
            addTexture(t1);

            // 2nd triangle
            addPoint(p1);
            addPoint(p4);
            addPoint(p3);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(t1);
            addTexture(t4);
            addTexture(t3);
        }
    }
}