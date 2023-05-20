#include "headers/torus.hpp"

map<int, vector<Point>> Torus::point_generator() {

    vector<Point> points = vector<Point>(), normals = vector<Point>();

    double sliceStep = (2*M_PI)/slices;
    double stackStep = (2*M_PI)/stacks;

    for(int slice = 0; slice < slices; slice++){

        for(int stack = 0; stack < stacks; stack++){

            Point p1 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos(stack * stackStep)      , ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin(stack * stackStep));
            Point p2 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos(stack * stackStep)      , ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin(stack * stackStep));
            Point p3 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos((stack + 1) * stackStep), ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin((stack + 1) * stackStep));
            Point p4 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos((stack + 1) * stackStep), ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin((stack + 1) * stackStep));

            Point v1 = Point(), v2 = Point(), normal1 = Point(), normal2 = Point(), normal3 = Point(), normal4 = Point();

            v1.subPoints(&p1, &p2);
            v2.subPoints(&p1, &p3);
            normal1.cross(&v1, &v2);
            normal1.normalize();

            v1.subPoints(&p2, &p3);
            v2.subPoints(&p2, &p4);
            normal2.cross(&v1, &v2);
            normal2.normalize();

            v1.subPoints(&p3, &p4);
            v2.subPoints(&p3, &p1);
            normal3.cross(&v1, &v2);
            normal3.normalize();

            v1.subPoints(&p4, &p1);
            v2.subPoints(&p4, &p2);
            normal4.cross(&v1, &v2);
            normal4.normalize();

            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p4);

            normals.push_back(normal1);
            normals.push_back(normal2);
            normals.push_back(normal4);

            points.push_back(p2);
            points.push_back(p3);
            points.push_back(p4);

            normals.push_back(normal2);
            normals.push_back(normal3);
            normals.push_back(normal4);
        }
    }
    return {{0, points}, {1, normals}};
}
