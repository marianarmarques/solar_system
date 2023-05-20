#include "headers/cone.hpp"

map<int, vector<Point>> Cone::point_generator() {

    vector<Point> points = vector<Point>(), normals = vector<Point>();

    float stack_height = height/stacks; 
    float angle = (2 * M_PI) / slices;

    for (int i = 0; i < slices; i++) { // Base e Lados
        
        Point p1 = Point(0.0f,0.0f,0.0f);
        Point p2 = Point(radius * sin(angle * (i+1)),0.0f,radius * cos(angle * (i+1)));
        Point p3 = Point(radius * sin(angle * i),0.0f,radius * cos(angle * i));
        Point p4 = Point(0.0f,height,0.0f);

        Point v11 = Point(), v12 = Point(), normal11 = Point(), normal12 = Point(), normal13 = Point(), normal14 = Point();

        v11.subPoints(&p1, &p2);
        v12.subPoints(&p1, &p3);
        normal11.cross(&v11, &v12);
        normal11.normalize();

        v11.subPoints(&p2, &p3);
        v12.subPoints(&p2, &p4);
        normal12.cross(&v11, &v12);
        normal12.normalize();

        v11.subPoints(&p3, &p4);
        v12.subPoints(&p3, &p1);
        normal13.cross(&v11, &v12);
        normal13.normalize();

        v11.subPoints(&p4, &p1);
        v12.subPoints(&p4, &p2);
        normal14.cross(&v11, &v12);
        normal14.normalize();
        
        // Base 
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);

        normals.push_back(normal11);
        normals.push_back(normal12);
        normals.push_back(normal13);

        // Lados
        points.push_back(p4);
        points.push_back(p3);
        points.push_back(p2);

        normals.push_back(normal14);
        normals.push_back(normal13);
        normals.push_back(normal12);

    }

    for(int i=1;i<stacks;i++){ // Stacks
        for(int j=0;j<slices;j++){
            Point p1 = Point((radius - (radius/stacks) * (i-1)) * sin(angle * (j+1)),stack_height*(i-1),(radius - (radius/stacks) * (i-1)) * cos(angle * (j+1)));
            Point p2 = Point((radius - (radius/stacks) * i) * sin(angle * (j+1)),stack_height*i,(radius - (radius/stacks) * i) * cos(angle * (j+1)));
            Point p3 = Point((radius - (radius/stacks) * i) * sin(angle * j),stack_height*i,(radius - (radius/stacks) * i) * cos(angle * j));

            Point v11 = Point(), v12 = Point(), normal11 = Point(), normal12 = Point(), normal13 = Point();

            v11.subPoints(&p1, &p2);
            v12.subPoints(&p1, &p3);
            normal11.cross(&v11, &v12);
            normal11.normalize();

            v11.subPoints(&p2, &p3);
            v12.subPoints(&p2, &p1);
            normal12.cross(&v11, &v12);
            normal12.normalize();

            v11.subPoints(&p3, &p1);
            v12.subPoints(&p3, &p2);
            normal13.cross(&v11, &v12);
            normal13.normalize();

            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p3);

            normals.push_back(normal11);
            normals.push_back(normal12);
            normals.push_back(normal13);

        }

    }

    return {{0, points}, {1, normals}};
}
