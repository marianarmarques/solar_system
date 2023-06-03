#include "headers/box.hpp"

void Box::point_generator() {

    float size = length / (float)grid,
          h_size = length / 2.0,
          div = 1.0f / grid;

    for(int i = 0; i < grid; i++) {
        for(int j = 0; j < grid; j++) {

            float px = -h_size + (size * j),      // x à esquerda <- num plano 2D
                  pz = h_size - (size * i),      // z a baixo    <- num plano 2D
                  px2 = -h_size + (size * (j+1)), // x à direita  <- num plano 2D
                  pz2 = h_size - (size * (i+1));  // z a cima     <- num plano 2D



            // Base superior
            Point p11 = Point(px, h_size, pz2),
                  p12 = Point(px, h_size, pz),
                  p13 = Point(px2, h_size, pz),
                  p14 = Point(px2, h_size, pz2);

            Point2D t11 = Point2D(i * div, (j+1) * div),
                    t12 = Point2D(i * div, j * div),
                    t13 = Point2D((i+1) * div, j * div),
                    t14 = Point2D((i+1) * div, (j+1) * div);

            // 1st triangle
            addPoint(p11);
            addPoint(p12);
            addPoint(p13);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t11);
            addTexture(t12);
            addTexture(t13);

            // 2nd triangle
            addPoint(p13);
            addPoint(p14);
            addPoint(p11);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t13);
            addTexture(t14);
            addTexture(t11);

            // Base inferior
            Point p21 = Point(px2, -h_size, pz),
                  p22 = Point(px, -h_size, pz),
                  p23 = Point(px, -h_size, pz2),
                  p24 = Point(px2, -h_size, pz2);
               
            Point2D t21 = Point2D((i+1) * div, j * div),
                    t22 = Point2D(i * div, j * div),
                    t23 = Point2D(i * div, (j+1) * div),
                    t24 = Point2D((i+1) * div, (j+1) * div);

            // 1st triangle
            addPoint(p21);
            addPoint(p22);
            addPoint(p23);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(t21);
            addTexture(t22);
            addTexture(t23);

            // 2nd triangle
            addPoint(p23);
            addPoint(p24);
            addPoint(p21);

            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));
            addNormal(Point(0, -1, 0));

            addTexture(t23);
            addTexture(t24);
            addTexture(t21);

            // Lateral 1 - virada para a esquerda
            Point p31 = Point(-h_size, px, pz2),
                  p32 = Point(-h_size, px, pz),
                  p33 = Point(-h_size, px2, pz),
                  p34 = Point(-h_size, px2, pz2);
            
            Point2D t32 = Point2D(i * div, (j+1) * div),
                    t33 = Point2D(i * div, j * div),
                    t34 = Point2D((i+1) * div, j * div),
                    t31 = Point2D((i+1) * div, (j+1) * div);

            // 1st triangle
            addPoint(p31);
            addPoint(p32); 
            addPoint(p33);

            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));

            addTexture(t31);
            addTexture(t32);
            addTexture(t33);

            // 2nd triangle
            addPoint(p33);
            addPoint(p34);
            addPoint(p31);

            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));
            addNormal(Point(-1, 0, 0));

            addTexture(t33);
            addTexture(t34);
            addTexture(t31);

            

            // Lateral 2 - virada para direita
            Point p41 = Point(h_size, px2, pz),
                  p42 = Point(h_size, px, pz),
                  p43 = Point(h_size, px, pz2),
                  p44 = Point(h_size, px2, pz2);

            Point2D t42 = Point2D((i+1) * div, j * div),
                    t43 = Point2D(i * div, j * div),
                    t44 = Point2D(i * div, (j+1) * div),
                    t41 = Point2D((i+1) * div, (j+1) * div);
            
            // 1st triangle
            addPoint(p41);
            addPoint(p42);
            addPoint(p43);

            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));

            addTexture(t41);
            addTexture(t42);
            addTexture(t43);

            // 2nd triangle
            addPoint(p43);
            addPoint(p44);
            addPoint(p41);

            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));
            addNormal(Point(1, 0, 0));

            addTexture(t43);
            addTexture(t44);
            addTexture(t41);



            // Lateral 3 - virada para trás
            Point p51 = Point(px, pz2, -h_size),
                  p52 = Point(px, pz, -h_size),
                  p53 = Point(px2, pz, -h_size),
                  p54 = Point(px2, pz2, -h_size);

            Point2D t51 = Point2D(i * div, (j+1) * div),
                    t52 = Point2D(i * div, j * div),
                    t53 = Point2D((i+1) * div, j * div),
                    t54 = Point2D((i+1) * div, (j+1) * div);

            // 1st triangle
            addPoint(p51);
            addPoint(p52);
            addPoint(p53);

            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));

            addTexture(t51);
            addTexture(t52);
            addTexture(t53);

            // 2nd triangle
            addPoint(p53);
            addPoint(p54);
            addPoint(p51);

            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));
            addNormal(Point(0, 0, -1));

            addTexture(t53);
            addTexture(t54);
            addTexture(t51);


            // Lateral 4 - virada para a frente
            Point p61 = Point(px2, pz, h_size),
                  p62 = Point(px, pz, h_size),
                  p63 = Point(px, pz2, h_size),
                  p64 = Point(px2, pz2, h_size);

            Point2D t61 = Point2D((i+1) * div, j * div),
                    t62 = Point2D(i * div, j * div),
                    t63 = Point2D(i * div, (j+1) * div),
                    t64 = Point2D((i+1) * div, (j+1) * div);

            // 1st triangle
            addPoint(p61);
            addPoint(p62);
            addPoint(p63);

            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));

            addTexture(t61);
            addTexture(t62);
            addTexture(t63);

            // 2nd triangle
            addPoint(p63);
            addPoint(p64);
            addPoint(p61);

            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));
            addNormal(Point(0, 0, 1));

            addTexture(t63);
            addTexture(t64);
            addTexture(t61);
        }
    }
}