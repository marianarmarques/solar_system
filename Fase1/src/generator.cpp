#include "./headers/box.hpp"
#include "./headers/plane.hpp"
#include "./headers/sphere.hpp"
#include "./headers/cone.hpp"
#include "./headers/primitive.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void create_3D_file(Primitive* primitive, string filename) {
    
    ofstream file("../3DFiles/" + filename);
    for(Point point : (*primitive).point_generator()){
        file << point.toString() << endl;
    }
}

void primitive_handler(int arg_numb, char** data) {
    string primitive_name = data[1];

    if (primitive_name == "box" && arg_numb == 5) {
        
        float length = stof(data[2]);
        int grid = stoi(data[3]);
        Box box(length, grid);

        create_3D_file(&box, data[4]);
    }
    else if (primitive_name == "sphere" && arg_numb == 6) {

        float radius = stof(data[2]);
        int slices = stoi(data[3]);
        int stacks = stoi(data[4]);
        Sphere sphere(radius, slices, stacks);

        create_3D_file(&sphere, data[5]);
    }
    else if (primitive_name == "plane" && arg_numb == 5) {

        float length = stof(data[2]);
        int grid = stoi(data[3]);
        Plane plane(length, grid);

        create_3D_file(&plane, data[4]);
    }
    else if (primitive_name == "cone" && arg_numb == 7) {

        float radius = stof(data[2]);
        float height = stof(data[3]);
        int slices = stoi(data[4]);
        int stacks = stoi(data[5]);
        Cone cone(radius,height, slices, stacks);

        create_3D_file(&cone, data[6]);
    }
    else {
        cout << primitive_name + " is not a valid solid name!" << endl;
    }
}

int main(int argc, char** argv) {

    if (argc > 1) {
        primitive_handler(argc, argv);
    }
    else {
        cout << "Not enough arguments provided!" << endl;
    }

    return 1;
}