#include "headers/sphere.hpp"

using namespace std;

void Sphere::point_generator() {

    float new_alfa = (2 * M_PI) / slices , 
          new_beta = M_PI / stacks,
          div_stacks = 1.0f/stacks,
          div_slices = 1.0f/slices;

    for(int i = 0; i < slices; i++) {

		for(int j = 0; j < stacks; j++) {

                  Point p1 = Point(radius * sin(new_beta * i) * cos(new_alfa * (j+1)), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * (j+1)));
                  Point p2 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * (j+1)), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * (j+1)));
                  Point p3 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * j), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * j));
                  Point p4 = Point(radius * sin(new_beta * i) * cos(new_alfa * j), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * j));

                  //printf("p1: (%f, %f, %f)\n", p1.getX(), p1.getZ(), p1.getY());
                  //printf("p2: (%f, %f, %f)\n", p2.getX(), p2.getZ(), p2.getY());
                  //printf("p3: (%f, %f, %f)\n", p3.getX(), p3.getZ(), p3.getY());
                  //printf("p4: (%f, %f, %f)\n", p4.getX(), p4.getZ(), p4.getY());

                  Point n11 = Point(sin(new_beta * i) * cos(new_alfa * (j+1)), cos(new_beta * i), sin(new_beta * i) * sin(new_alfa * (j+1)));
                  Point n12 = Point(sin(new_beta * (i+1)) * cos(new_alfa * (j+1)),  cos(new_beta * (i+1)),  sin(new_beta * (i+1)) * sin(new_alfa * (j+1)));
                  Point n13 = Point(sin(new_beta * (i+1)) * cos(new_alfa * j),  cos(new_beta * (i+1)),  sin(new_beta * (i+1)) * sin(new_alfa * j));
                  Point n14 = Point(sin(new_beta * i) * cos(new_alfa * j),  cos(new_beta * i),  sin(new_beta * i) * sin(new_alfa * j));

                  Point2D t2 = Point2D(0.25 + 1- (j+1) * div_stacks, 1- (i+1) * div_slices);
                  Point2D t1 = Point2D(0.25 + 1- (j+1) * div_stacks, 1- i * div_slices);
                  Point2D t4 = Point2D(0.25 + 1- j * div_stacks,     1- i * div_slices);
                  Point2D t3 = Point2D(0.25 + 1- j * div_stacks,     1- (i+1) * div_slices);

                  // 1st triangle
                  addPoint(p1);
                  addPoint(p2);
                  addPoint(p3);

                  addNormal(n11);
                  addNormal(n12);
                  addNormal(n13);

                  addTexture(t1);
                  addTexture(t2);
                  addTexture(t3);

                  // 2nd triangle
                  addPoint(p3);
                  addPoint(p4);
                  addPoint(p1);

                  addNormal(n13);
                  addNormal(n14);
                  addNormal(n11);

                  addTexture(t3);
                  addTexture(t4);
                  addTexture(t1);
            }
	}
}