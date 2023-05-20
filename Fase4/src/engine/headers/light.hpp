#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../../utils/headers/point.hpp"
#include "../../utils/headers/tinyxml2.hpp"
#include "GL/glut.h"
#include <vector>
#include <iostream>

class Light {
    private:
        int id;

    public:
        int getId() const {return id;}

        virtual void doAction() = 0;

        virtual void printLight() = 0;

        Light(int id) {
            this->id = GL_LIGHT0 + id;
        }
};

class PointLight : public Light {
    private:
        Point position;

    public:
        Point getPosition() const {return position;}

        void doAction() {
            float pos[4] = {position.getX(), position.getY(), position.getZ(), 1.0};
            glLightfv(getId(), GL_POSITION, pos);
        }

        void printLight() {
            cout << "Point Light" << endl;
            cout << "Position: " << position.getX() << " " << position.getY() << " " << position.getZ() << endl;
        }

        PointLight(int id, Point position) : Light(id) {
            this->position = position;
        }
};

class DirectionalLight : public Light {
    private:
        Point direction;

    public:
        Point getDirection() const {return direction;}

        void doAction() {
            float dir[4] = {direction.getX(), direction.getY(), direction.getZ(), 0.0};            
            glLightfv(getId(), GL_POSITION, dir);
        }

        void printLight() {
            cout << "Id: " << getId() << endl; 
            cout << "Directional Light" << endl;
            cout << "Direction: " << direction.getX() << " " << direction.getY() << " " << direction.getZ() << endl;
        }

        DirectionalLight(int id, Point direction) : Light(id) {
            this->direction = direction;
        }
};

class SpotLight : public Light {
    private:
        Point position, direction;
        float cutoff;

    public:
        Point getPosition() const {return position;}
        Point getDirection() const {return direction;}
        float getCutoff() const {return cutoff;}

        void doAction() {
            float pos[4] = {position.getX(), position.getY(), position.getZ(), 1.0};
            float dir[4] = {direction.getX(), direction.getY(), direction.getZ(), 0.0};
            glLightfv(getId(), GL_POSITION, pos);
            glLightfv(getId(), GL_SPOT_DIRECTION, dir);
            glLightf(getId(), GL_SPOT_CUTOFF, cutoff);
        }

        void printLight() {
            cout << "Spot Light" << endl;
            cout << "Position: " << position.getX() << " " << position.getY() << " " << position.getZ() << endl;
            cout << "Direction: " << direction.getX() << " " << direction.getY() << " " << direction.getZ() << endl;
            cout << "Cutoff: " << cutoff << endl;
        }

        SpotLight(int id, Point position, Point direction, float cutoff) : Light(id) {
            this->position = position;
            this->direction = direction;
            this->cutoff = cutoff;
        }
};

class Lights {
    private:
        vector<Light*> lights;
    
    public:
        vector<Light*> getLights() const {return lights;}
        
        void addLight(Light *light) {
            lights.push_back(light);
        }

        void doAction() {
            for (int i = 0; i < lights.size(); i++) {
                lights[i]->doAction();
            }
        }

        void printLights() {
            for (int i = 0; i < lights.size(); i++) {
                lights[i]->printLight();
            }
        }

        Lights() {
            this->lights = vector<Light*>();
        }

        Lights(vector<Light*> lights) {
            this->lights = lights;
        }
};

Lights readLights(tinyxml2::XMLNode *root);
#endif