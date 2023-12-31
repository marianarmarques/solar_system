#include "headers/torus.hpp"

vector<Point> Torus::point_generator() {

    std::vector<Point> torus;

    double sliceStep = (2*M_PI)/slices;
    double stackStep = (2*M_PI)/stacks;

    for(int slice = 0; slice < slices; slice++){

        for(int stack = 0; stack < stacks; stack++){

            Point p1 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos(stack * stackStep)      , ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin(stack * stackStep));
            Point p2 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos(stack * stackStep)      , ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin(stack * stackStep));
            Point p3 = Point((radius + ringRadius * cos((slice + 1) * sliceStep)) * cos((stack + 1) * stackStep), ringRadius * sin((slice + 1) * sliceStep), (radius + ringRadius * cos((slice + 1) * sliceStep)) * sin((stack + 1) * stackStep));
            Point p4 = Point((radius + ringRadius * cos(slice * sliceStep))       * cos((stack + 1) * stackStep), ringRadius * sin(slice * sliceStep)      , (radius + ringRadius * cos(slice * sliceStep))       * sin((stack + 1) * stackStep));

            torus.push_back(p1);
            torus.push_back(p2);
            torus.push_back(p4);

            torus.push_back(p2);
            torus.push_back(p3);
            torus.push_back(p4);
        }
    }
    return torus;
}
