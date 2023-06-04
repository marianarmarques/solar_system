#include "headers/cone.hpp"

void Cone::point_generator() {

    float alpha = (2 * M_PI) / slices,
          div_slices = 1.0f/slices,
          div_stacks = 1.0f/stacks;       

    for(float i=0; i<slices; i++) {
        
        for(float j=0; j<stacks; j++) {

            float stackHeight = (height / stacks) * j,
                  nextRadius = (height - stackHeight) * radius / height,
                  stackHeight2 = (height / stacks) * (j + 1),
                  nextRadius2 = (height - stackHeight2) * radius / height;    
             
            if (j==0) { // Base
                addPoint(Point(0, height, 0));
                addPoint(Point(radius * cos((i+1)*alpha), 0, radius*-sin((i+1)*alpha)));
                addPoint(Point(radius * cos(i*alpha), 0, radius*-sin(i*alpha)));

                addNormal(Point(0,-1,0));
                addNormal(Point(0,-1,0));
                addNormal(Point(0,-1,0));

                addTexture(Point2D((i+1) * div_slices, 0));
                addTexture(Point2D(i * div_slices, 0));
                addTexture(Point2D((i + 0.5) * div_slices, 1));
            }

            Point p4 = Point(nextRadius2 * cos(alpha * i), stackHeight2, nextRadius2 * sin(alpha * i)), 
                  p5 = Point(nextRadius2 * cos(alpha * (i + 1)), stackHeight2, nextRadius2 * sin(alpha * (i + 1))), 
                  p6 = Point(nextRadius * cos(alpha * i), stackHeight, nextRadius * sin(alpha * i)),
                  p7 = Point(nextRadius * cos(alpha * (i + 1)), stackHeight, nextRadius * sin(alpha * (i + 1)));                 
            
            Point v1 = Point(), 
                  v2 = Point(),
                  n4 = Point(),
                  n5 = Point(),
                  n6 = Point(),
                  n7 = Point();
            
            Point2D t4 = Point2D(i * div_slices,       (j + 1) * div_stacks),
                    t5 = Point2D((i + 1) * div_slices, (j + 1) * div_stacks),
                    t6 = Point2D((i + 1) * div_slices, j * div_stacks),
                    t7 = Point2D(i * div_slices,       j * div_stacks);

            v1.subPoints(&p5, &p4);
            v2.subPoints(&p6, &p4);
            n4.cross(&v1, &v2);
            n4.normalize();

            v1.subPoints(&p4, &p5);
            v2.subPoints(&p7, &p5);
            n5.cross(&v1, &v2);
            n5.normalize();

            v1.subPoints(&p7, &p6);
            v2.subPoints(&p4, &p6);
            n6.cross(&v1, &v2);
            n6.normalize();

            v1.subPoints(&p6, &p7);
            v2.subPoints(&p5, &p7);
            n7.cross(&v1, &v2);
            n7.normalize();

            // 1st triangle 
            addPoint(p4);
            addPoint(p5);
            addPoint(p6);

            addNormal(n4);
            addNormal(n5);
            addNormal(n6);

            addTexture(t4);
            addTexture(t5);
            addTexture(t6);

            // 2nd triangle
            addPoint(p6);
            addPoint(p5);
            addPoint(p7);

            addNormal(n6);
            addNormal(n5);
            addNormal(n7);

            addTexture(t6);
            addTexture(t5);
            addTexture(t7);
        }
    }
}
