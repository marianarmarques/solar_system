#include "headers/sphere.hpp"

using namespace std;

vector<Point> Sphere::point_generator() {

    vector<Point> points;
    
    float new_alfa = (2 * M_PI) / slices , new_beta = M_PI / stacks;

    for(int i = 0; i < stacks; i++) {
		for(int j = 1; j <= slices; j++) {

            points.push_back(Point(radius * sin(new_beta * i) * cos(new_alfa * (j+1)), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * (j+1))));
            points.push_back(Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * (j+1)), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * (j+1))));
            points.push_back(Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * j), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * j)));

            points.push_back(Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * j), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * j)));
            points.push_back(Point(radius * sin(new_beta * i) * cos(new_alfa * j), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * j)));
            points.push_back(Point(radius * sin(new_beta * i) * cos(new_alfa * (j+1)), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * (j+1))));
		}
	}

    return points;
}