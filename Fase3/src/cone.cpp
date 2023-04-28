#include "headers/cone.hpp"

vector<Point> Cone::point_generator() {

    vector<Point> points;

    float stack_height = height/stacks; 
    float angle = (2 * M_PI) / slices;

    for (int i = 0; i < slices; i++) { // Base e Lados
        
        // Base 
        points.push_back(Point(0.0f,0.0f,0.0f));
        points.push_back(Point(radius * sin(angle * (i+1)),0.0f,radius * cos(angle * (i+1))));
        points.push_back(Point(radius * sin(angle * i),0.0f,radius * cos(angle * i)));


        // Lados
        points.push_back(Point(0.0f,height,0.0f));
        points.push_back(Point(radius * sin(angle * i),0.0f,radius * cos(angle * i)));
        points.push_back(Point(radius * sin(angle * (i+1)),0.0f,radius * cos(angle * (i+1))));

    }

    for(int i=1;i<stacks;i++){ // Stacks
        for(int j=0;j<slices;j++){
            
            points.push_back(Point((radius - (radius/stacks) * (i-1)) * sin(angle * (j+1)),stack_height*(i-1),(radius - (radius/stacks) * (i-1)) * cos(angle * (j+1))));
            points.push_back(Point((radius - (radius/stacks) * i) * sin(angle * (j+1)),stack_height*i,(radius - (radius/stacks) * i) * cos(angle * (j+1))));
            points.push_back(Point((radius - (radius/stacks) * i) * sin(angle * j),stack_height*i,(radius - (radius/stacks) * i) * cos(angle * j)));

        }

    }

    return points;
}
