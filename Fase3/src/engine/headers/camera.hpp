#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../../utils/headers/point.hpp"
#include "../../utils/headers/tinyxml2.hpp"
#include <iostream>

using namespace std;

class Camera {
    private:
        Point position, up, lookAt, projection; 

    public:
        Point getPosition() const {return position;}
        Point getLookAt() const {return lookAt;}
        Point getUp() const {return up;}
        Point getProjection() const {return projection;} 
        
        void printCamera() {
            cout << "Camera position: " << getPosition().getX() << " " << getPosition().getY() << " " << getPosition().getZ() << endl;
            cout << "Camera lookAt: " << getLookAt().getX() << " " << getLookAt().getY() << " " << getLookAt().getZ() << endl;
            cout << "Camera up: " << getUp().getX() << " " << getUp().getY() << " " << getUp().getZ() << endl;
            cout << "Camera projection: " << getProjection().getX() << " " << getProjection().getY() << " " << getProjection().getZ() << endl;
        }

        Camera() {
            position = Point();
            up = Point();
            lookAt = Point();
            projection = Point();
        }

        Camera(Point position, Point up, Point lookAt, Point projection) {
            this->position = position;
            this->up = up;
            this->lookAt = lookAt;
            this->projection = projection;
        }
};

Camera readCamera(tinyxml2::XMLNode *root);

#endif