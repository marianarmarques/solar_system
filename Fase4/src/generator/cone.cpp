#include "headers/cone.hpp"

void Cone::point_generator() {

    float alpha = (2 * M_PI) / slices;       
    // float beta = M_PI / stacks;   

    for(float i=0; i<slices; i++) {
        
        for(float j=0; j<stacks; j++) {
            float stackHeight = (height / stacks) * j,
                  nextRadius = (height - stackHeight) * radius / height,
                  stackHeight2 = (height / stacks) * (j + 1),
                  nextRadius2 = (height - stackHeight2) * radius / height;
                
            float hip1 = sqrt(pow(nextRadius, 2) + pow(stackHeight, 2));
            float cone_x1 = nextRadius / hip1;
            float cone_y1 = -stackHeight / hip1;

            float hip2 = sqrt(pow(nextRadius2, 2) + pow(stackHeight2, 2));
            float cone_x2 = nextRadius2 / hip2;
            float cone_y2 = -stackHeight2 / hip2; 
             
            if (j==0) { // Base
                Point p1 = Point(0,0,0);
                Point p2 = Point(radius * cos((i+1)*alpha), 0, radius*-sin((i+1)*alpha));
                Point p3 = Point(radius * cos(i*alpha), 0, radius*-sin(i*alpha));

                addPoint(p1);
                addPoint(p2);
                addPoint(p3);

                /*addNormal(Point(0,-1,0));
                addNormal(Point(0,-1,0));
                addNormal(Point(0,-1,0));*/

                /*// Cone Bottom Normal
                vertices.add(-cone_y * cos);
                vertices.add( cone_x );
                vertices.add(-cone_y * sin);*/

                addNormal(Point(-cone_y1 * cos(alpha * i), cone_x1, -cone_y1 * sin(alpha * i)));
                addNormal(Point(-cone_y1 * cos(alpha * (i + 1)), cone_x1, -cone_y1 * sin(alpha * (i + 1))));
                addNormal(Point(-cone_y2 * cos(alpha * i), cone_x2, -cone_y2 * sin(alpha * i)));


            }

            Point p4 = Point(nextRadius2 * cos(alpha * i), stackHeight2, nextRadius2 * sin(alpha * i)), 
                  p5 = Point(nextRadius2 * cos(alpha * (i + 1)), stackHeight2, nextRadius2 * sin(alpha * (i + 1))), 
                  p6 = Point(nextRadius * cos(alpha * i), stackHeight, nextRadius * sin(alpha * i)),
                  p7 = Point(nextRadius * cos(alpha * (i + 1)), stackHeight, nextRadius * sin(alpha * (i + 1)));
                  /*v1 = Point(),
                  v2 = Point(),
                  n4 = Point(),
                  n5 = Point(),
                  n6 = Point(),
                  n7 = Point();    */              

            Point n4 = Point(-cone_y2 * cos(alpha * i), cone_x2, -cone_y2 * sin(alpha * i));
            n4.normalize();
            Point n5 = Point(-cone_y2 * cos(alpha * (i + 1)), cone_x2, -cone_y2 * sin(alpha * (i + 1)));
            n5.normalize();
            Point n6 = Point(-cone_y1 * cos(alpha * i), cone_x1, -cone_y1 * sin(alpha * i));
            n6.normalize();
            Point n7 = Point(-cone_y1 * cos(alpha * (i + 1)), cone_x1, -cone_y1 * sin(alpha * (i + 1)));
            n7.normalize();

            /*v1.subPoints(&p5, &p4);
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
            n7.normalize();*/



            // 1st triangle 
            addPoint(p4);
            addPoint(p5);
            addPoint(p6);

            addNormal(n4);
            addNormal(n5);
            addNormal(n6);

            // 2nd triangle
            addPoint(p6);
            addPoint(p5);
            addPoint(p7);

            addNormal(n6);
            addNormal(n5);
            addNormal(n7);
        }
    }
}
