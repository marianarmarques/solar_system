#include "headers/sphere.hpp"

using namespace std;

map<int, vector<Point>> Sphere::point_generator() {

    vector<Point> points;
    vector<Point> normals;
    
    float new_alfa = (2 * M_PI) / slices , new_beta = M_PI / stacks;

    for(int i = 0; i < stacks; i++) {
		for(int j = 1; j <= slices; j++) {

            Point p1 = Point(radius * sin(new_beta * i) * cos(new_alfa * (j+1)), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * (j+1)));
            Point p2 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * (j+1)), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * (j+1)));
            Point p3 = Point(radius * sin(new_beta * (i+1)) * cos(new_alfa * j), radius * cos(new_beta * (i+1)), radius * sin(new_beta * (i+1)) * sin(new_alfa * j));
            Point p4 = Point(radius * sin(new_beta * i) * cos(new_alfa * j), radius * cos(new_beta * i), radius * sin(new_beta * i) * sin(new_alfa * j));

            Point v1 = Point(), v2 = Point(), normal11 = Point(), normal12 = Point(), normal13 = Point(), normal14 = Point();

            v1.subPoints(&p1, &p2);
            v2.subPoints(&p1, &p3);
            normal11.cross(&v1, &v2);
            normal11.normalize();

            v1.subPoints(&p2, &p3);
            v2.subPoints(&p2, &p4);
            normal12.cross(&v1, &v2);
            normal12.normalize();

            v1.subPoints(&p3, &p4);
            v2.subPoints(&p3, &p1);
            normal13.cross(&v1, &v2);
            normal13.normalize();

            v1.subPoints(&p4, &p1);
            v2.subPoints(&p4, &p2);
            normal14.cross(&v1, &v2);
            normal14.normalize();

            // 1st triangle
            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p3);

            normals.push_back(normal11);
            normals.push_back(normal12);
            normals.push_back(normal13);

            // 2nd triangle
            points.push_back(p3);
            points.push_back(p4);
            points.push_back(p1);

            normals.push_back(normal13);
            normals.push_back(normal14);
            normals.push_back(normal11);
		}
	}

    return {{0, points}, {1, normals}};
}