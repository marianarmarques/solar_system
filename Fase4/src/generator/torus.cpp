#include "headers/torus.hpp"

void Torus::point_generator() {

    vector<Point> points = vector<Point>(), normals = vector<Point>();

    double sliceStep = (2*M_PI) / slices,
           stackStep = (2*M_PI) / stacks,
           div_slices = 1.0f / slices,
           div_stacks = 1.0f / stacks;

    for(int slice = 0; slice < slices; slice++){

        for(int stack = 0; stack < stacks; stack++){

            Point p1 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos(stack * stackStep)      , ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin(stack * stackStep)),
                  p2 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos(stack * stackStep)      , ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin(stack * stackStep)),
                  p3 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos((stack + 1) * stackStep), ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin((stack + 1) * stackStep)),
                  p4 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos((stack + 1) * stackStep), ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin((stack + 1) * stackStep));

            Point2D t1 = Point2D(slice * div_slices, stack * div_stacks),
                    t2 = Point2D((slice + 1) * div_slices,stack * div_stacks),
                    t3 = Point2D((slice + 1) * div_slices, (stack + 1) * div_stacks),
                    t4 = Point2D(slice * div_slices, (stack+1) * div_stacks);

            // 1st triangle
            addPoint(p1);
            addPoint(p2);
            addPoint(p4);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t1);
            addTexture(t2);
            addTexture(t4);


            // 2nd triangle
            addPoint(p2);
            addPoint(p3);
            addPoint(p4);

            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));
            addNormal(Point(0, 1, 0));

            addTexture(t2);
            addTexture(t3);
            addTexture(t4);
        }
    }
}
