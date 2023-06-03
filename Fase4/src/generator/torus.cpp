#include "headers/torus.hpp"

void Torus::point_generator() {

    vector<Point> points = vector<Point>(), normals = vector<Point>();

    double sliceStep = (2*M_PI)/slices;
    double stackStep = (2*M_PI)/stacks;

    for(int slice = 0; slice < slices; slice++){

        for(int stack = 0; stack < stacks; stack++){

            Point p1 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos(stack * stackStep)      , ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin(stack * stackStep));
            Point p2 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos(stack * stackStep)      , ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin(stack * stackStep));
            Point p3 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos((stack + 1) * stackStep), ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin((stack + 1) * stackStep));
            Point p4 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos((stack + 1) * stackStep), ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin((stack + 1) * stackStep));

            Point v1 = Point(), 
                  v2 = Point(), 
                  n1 = Point(), 
                  n2 = Point(), 
                  n3 = Point(), 
                  n4 = Point();

            v1.subPoints(&p1, &p2);
            v2.subPoints(&p1, &p3);
            n1.cross(&v1, &v2);
            n1.normalize();

            v1.subPoints(&p2, &p3);
            v2.subPoints(&p2, &p4);
            n2.cross(&v1, &v2);
            n2.normalize();

            v1.subPoints(&p3, &p4);
            v2.subPoints(&p3, &p1);
            n3.cross(&v1, &v2);
            n3.normalize();

            v1.subPoints(&p4, &p1);
            v2.subPoints(&p4, &p2);
            n4.cross(&v1, &v2);
            n4.normalize();

            // 1st triangle
            addPoint(p1);
            addPoint(p2);
            addPoint(p4);

            addNormal(n1);
            addNormal(n2);
            addNormal(n4);

            // 2nd triangle
            addPoint(p2);
            addPoint(p3);
            addPoint(p4);

            addNormal(n2);
            addNormal(n3);
            addNormal(n4);
        }
    }
}
