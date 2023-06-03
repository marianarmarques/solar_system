#include "headers/box.hpp"

void Box::point_generator() {

    float size = length / (float)grid;
    float h_size = length / 2.0;
    float px = 0, pz = 0, px2 = 0, pz2 = 0;

    for(int i = 0; i < grid; i++) {
        for(int j = 0; j < grid; j++) {

            px = -h_size + (size * j);      // x à esquerda <- num plano 2D
            pz = h_size - (size * i);       // z a baixo    <- num plano 2D
            px2 = -h_size + (size * (j+1)); // x à direita  <- num plano 2D
            pz2 = h_size - (size * (i+1));  // z a cima     <- num plano 2D



            // Base superior
            Point p11 = Point(px, h_size, pz2);
            Point p12 = Point(px, h_size, pz);
            Point p13 = Point(px2, h_size, pz);
            Point p14 = Point(px2, h_size, pz2);

            // 1st triangle
            addPoint(p11);
            addPoint(p12);
            addPoint(p13);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            // 2nd triangle
            addPoint(p13);
            addPoint(p14);
            addPoint(p11);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));



            // Base inferior
            Point p21 = Point(px2, -h_size, pz);
            Point p22 = Point(px, -h_size, pz);
            Point p23 = Point(px, -h_size, pz2);
            Point p24 = Point(px2, -h_size, pz2);

            // 1st triangle
            addPoint(p21);
            addPoint(p22);
            addPoint(p23);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            // 2nd triangle
            addPoint(p23);
            addPoint(p24);
            addPoint(p21);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));



            // Lateral 1 - virada para a esquerda
            Point p31 = Point(-h_size, px, pz2);
            Point p32 = Point(-h_size, px, pz);
            Point p33 = Point(-h_size, px2, pz);
            Point p34 = Point(-h_size, px2, pz2);

            // 1st triangle
            addPoint(p31);
            addPoint(p32); 
            addPoint(p33);

            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));

            // 2nd triangle
            addPoint(p33);
            addPoint(p34);
            addPoint(p31);

            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));



            // Lateral 2 - virada para direita
            Point p41 = Point(h_size, px2, pz);
            Point p42 = Point(h_size, px, pz);
            Point p43 = Point(h_size, px, pz2);
            Point p44 = Point(h_size, px2, pz2);
            
            // 1st triangle
            addPoint(p41);
            addPoint(p42);
            addPoint(p43);

            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));

            // 2nd triangle
            addPoint(p43);
            addPoint(p44);
            addPoint(p41);

            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));



            // Lateral 3 - virada para trás
            Point p51 = Point(px, pz2, -h_size);
            Point p52 = Point(px, pz, -h_size);
            Point p53 = Point(px2, pz, -h_size);
            Point p54 = Point(px2, pz2, -h_size);

            // 1st triangle
            addPoint(p51);
            addPoint(p52);
            addPoint(p53);

            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));

            // 2nd triangle
            addPoint(p53);
            addPoint(p54);
            addPoint(p51);

            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));

    

            // Lateral 4 - virada para a frente
            Point p61 = Point(px2, pz, h_size);
            Point p62 = Point(px, pz, h_size);
            Point p63 = Point(px, pz2, h_size);
            Point p64 = Point(px2, pz2, h_size);

            // 1st triangle
            addPoint(p61);
            addPoint(p62);
            addPoint(p63);

            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));

            // 2nd triangle
            addPoint(p63);
            addPoint(p64);
            addPoint(p61);

            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));
        }
    }
}