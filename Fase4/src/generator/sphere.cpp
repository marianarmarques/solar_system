#include "headers/sphere.hpp"

using namespace std;

void Sphere::point_generator() {

    float new_alfa = (2 * M_PI) / slices , new_beta = M_PI / stacks;

    for(int i = 0; i < stacks; i++) {
		for(int j = 1; j <= slices; j++) {

            Point p1 = Point(radius * sin(new_beta * i) * cos(new_alfa * (j+1)), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * (j+1)));
            Point p2 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * (j+1)), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * (j+1)));
            Point p3 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * j), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * j));
            Point p4 = Point(radius * sin(new_beta * i) * cos(new_alfa * j), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * j));

            Point n11 = Point(sin(new_beta * i) * cos(new_alfa * (j+1)), cos(new_beta * i), sin(new_beta * i) * sin(new_alfa * (j+1)));
            Point n12 = Point( sin(new_beta * (i+1)) * cos(new_alfa * (j+1)),  cos(new_beta * (i+1)),  sin(new_beta * (i+1)) * sin(new_alfa * (j+1)));
            Point n13 = Point( sin(new_beta * (i+1)) * cos(new_alfa * j),  cos(new_beta * (i+1)),  sin(new_beta * (i+1)) * sin(new_alfa * j));
            Point n14 = Point( sin(new_beta * i) * cos(new_alfa * j),  cos(new_beta * i),  sin(new_beta * i) * sin(new_alfa * j));


            // 1st triangle
            addPoint(p1);
            addPoint(p2);
            addPoint(p3);

            addNormal(n11);
            addNormal(n12);
            addNormal(n13);

            // 2nd triangle
            addPoint(p3);
            addPoint(p4);
            addPoint(p1);

            addNormal(n13);
            addNormal(n14);
            addNormal(n11);
		}
	}
}