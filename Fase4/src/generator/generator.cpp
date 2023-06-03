#include "./headers/plane.hpp"
#include "./headers/box.hpp"
#include "./headers/sphere.hpp"
#include "./headers/cone.hpp"
#include "./headers/torus.hpp"
#include "./headers/bezier.hpp"
#include "./headers/primitive.hpp"
#include <iostream>
#include <fstream>

void create_3D_file(Primitive* primitive, string filename) {
    
    ofstream file("../3DFiles/" + filename);

    primitive->point_generator();

    file << primitive->getPoints().size() << endl;
    for(auto it = primitive->getPoints().begin(); it != primitive->getPoints().end(); it++) {
        file << (*it).getX() << " " << (*it).getY() << " " << (*it).getZ() << endl;
    }

    file << primitive->getNormals().size() << endl;
    for(auto it = primitive->getNormals().begin(); it != primitive->getNormals().end(); it++) {
        file << (*it).getX() << " " << (*it).getY() << " " << (*it).getZ() << endl;
    }

    file << primitive->getTextures().size() << endl;
    for(auto it = primitive->getTextures().begin(); it != primitive->getTextures().end(); it++) {
        file << (*it).getX() << " " << (*it).getY() << endl;
    }
}

void primitive_handler(int arg_numb, char** data) {
    string primitive_name = data[1];

    if (primitive_name == "plane" && arg_numb == 5) {

        float length = stof(data[2]);
        int grid = stoi(data[3]);
        Plane plane(length, grid);

        create_3D_file(&plane, data[4]);
    }
    else if (primitive_name == "box" && arg_numb == 5) {
        
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
    else if (primitive_name == "cone" && arg_numb == 7) {

        float radius = stof(data[2]);
        float height = stof(data[3]);
        int slices = stoi(data[4]);
        int stacks = stoi(data[5]);
        Cone cone(radius, height, slices, stacks);

        create_3D_file(&cone, data[6]);
    }
    else if (primitive_name == "torus" && arg_numb == 7) {

        float radius = stof(data[2]);
        float ringRadius = stof(data[3]);
        int slices = stoi(data[4]);
        int stacks = stoi(data[5]);
        Torus torus(radius, ringRadius, slices, stacks);

        create_3D_file(&torus, data[6]);
    }
    else if (primitive_name == "bezier" && arg_numb == 5) {
        // ./generator bezier teapot.patch 10 teapot.3d

        string file = data[2];
        int tessellation = stoi(data[3]);
        Bezier bezier(file, tessellation);

        create_3D_file(&bezier, data[4]);
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