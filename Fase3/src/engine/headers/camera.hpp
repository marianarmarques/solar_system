#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../../utils/headers/point.hpp"
#include "../../utils/headers/tinyxml2.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class Camera {
    private:
        Point position, up, lookAt, projection;
        float alpha, betha, radius; 

    public:
        Point getPosition() const {return position;}
        Point getLookAt() const {return lookAt;}
        Point getUp() const {return up;}
        Point getProjection() const {return projection;} 
        float getAlpha() const {return alpha;}
        float getBetha() const {return betha;}
        float getRadius() const {return radius;}
        
        void setAlpha(float a, char c) {
            switch (c)
            {
            case '+':
                this->alpha += a;
                break;
            case '-':
                this->alpha -= a;
                break;
            case '=':
                this->alpha = a;
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }
        
        void setBetha(float b, char c) {
            switch (c)
            {
            case '+':
                this->betha += b;
                break;
            case '-':
                this->betha -= b;
                break;
            case '=':
                this->betha = b;
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }

        void setRadius(float r, char c) {
            switch (c) 
            {
            case '+':
                this->radius += r;
                break;
            case '-':
                this->radius -= r;
                break;
            case '=':
                this->radius = r;
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }

        void moveCamera();
        void convertToSpherical();
        
        void printCamera() {
            cout << "Camera position: " << getPosition().getX() << " " << getPosition().getY() << " " << getPosition().getZ() << endl;
            cout << "Camera lookAt: " << getLookAt().getX() << " " << getLookAt().getY() << " " << getLookAt().getZ() << endl;
            cout << "Camera up: " << getUp().getX() << " " << getUp().getY() << " " << getUp().getZ() << endl;
            cout << "Camera projection: " << getProjection().getX() << " " << getProjection().getY() << " " << getProjection().getZ() << endl;
            cout << "Camera alpha: " << alpha << endl;
            cout << "Camera betha: " << betha << endl;
            cout << "Camera radius: " << radius << endl;
        }

        Camera() {
            position = Point();
            up = Point();
            lookAt = Point();
            projection = Point();
            alpha = 0;
            betha = 0;
            radius = 0;
        }

        Camera(Point position, Point up, Point lookAt, Point projection, float alpha, float betha, float radius) {
            this->position = position;
            this->up = up;
            this->lookAt = lookAt;
            this->projection = projection;
            this->alpha = alpha;
            this->betha = betha;
            this->radius = radius;
        }
};

Camera readCamera(tinyxml2::XMLNode *root);

#endif