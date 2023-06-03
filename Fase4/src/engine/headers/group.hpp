#ifndef GROUP_HPP
#define GROUP_HPP

#include <IL/il.h>
#include <GL/glew.h>
#include "GL/glut.h"
#include "../../utils/headers/tinyxml2.hpp"
#include "../../utils/headers/point.hpp"
#include "../../utils/headers/point2d.hpp"
#include "../../utils/headers/utils.hpp"
#include "window.hpp"
#include "camera.hpp"
#include "light.hpp"
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class Transform {
    private:
        float x, y, z;

    public:
        float getX() const {return x;}
        float getY() const {return y;}
        float getZ() const {return z;}

        virtual void printTransform() = 0;
        virtual void doAction(float t) = 0;

        Transform() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        Transform(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

class Translation : public Transform {
    private:
        float time;
        bool align;
        vector<Point> points;

    public:
        float getTime() const {return time;}
        float getAlign() const {return align;}
        vector<Point> getPoints() const {return points;}

        void getCatmullRomPoint(float t, Point p1, Point p2, Point p3, Point p4, Point *pos, Point *deriv);
        void getGlobalCatmullRomPoint(float gt, Point *pos, Point *deriv);
        void renderCatmullRoomCurve();
        void alignModel(Point *deriv);

        void printTransform() {
            cout << "Translation: " << time << " " << align << endl;
            for (int i = 0; i < points.size(); i++) {
                cout << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << endl;
            }
        }

        void doAction(float t) {
            if(points.empty()) {
                glTranslatef(getX(), getY(), getZ());
                return;
            }
            
            renderCatmullRoomCurve();
            int start = t/time;
            t-= start * time;
            Point pos = Point(), deriv = Point();
            getGlobalCatmullRomPoint(t/time, &pos, &deriv);
            glTranslatef(pos.getX(), pos.getY(), pos.getZ());

            if(align) alignModel(&deriv);
        }

        Translation() : Transform() {
            this->time = -1;
            this->align = false;
            this->points = vector<Point>();

        }

        Translation(float x, float y, float z) : Transform(x, y, z) {
            this->time = -1;
            this->align = false;
            this->points = vector<Point>();
        }

        Translation(float time, bool align, vector<Point> points) : Transform() {
            this->time = time;
            this->align = align;
            this->points = points;
        }
};

class Rotation : public Transform {
    private:
        float angle, time;

    public:
        float getAngle() const {return angle;}
        float getTime() const {return time;}
        
        void printTransform() {
            cout << "Rotation: " << angle << " " << time << " " << getX() << " " << getY() << " " << getZ() << endl;
        } 

        void doAction(float t) {
            float newAngle = 0;

            if(time != -1) {
                int start = t/time;
                t-= start * time;
                newAngle = 360 * (t / time);
            }


            glRotatef(angle + newAngle, getX(), getY(), getZ());
        }

        Rotation() : Transform() {
            this->angle = 0;
            this->time = -1;
        }

        Rotation(float angle, float time, float x, float y, float z) : Transform(x, y, z) {
            this->angle = angle;
            this->time = time;
        }
};

class Scale : public Transform {
    public:

        void printTransform() {
            cout << "Scale: " << getX() << " " << getY() << " " << getZ() << endl;
        }

        void doAction(float t) {
            glScalef(getX(), getY(), getZ());
        }

        Scale(float x, float y, float z) : Transform(x, y, z) {}
};

class Transforms {
    private:
        vector<Transform*> transforms;

    public:
        vector<Transform*> getTransforms() const {return transforms;}
        
        void addTransform(Transform &t) {transforms.push_back(&t);}

        void printTransforms() {
            for (int i = 0; i < transforms.size(); i++) {
                transforms.at(i)->printTransform();
            }
        }

        Transforms() {
            transforms = vector<Transform*>();
        }

        Transforms(vector<Transform*> transforms) {
            this->transforms = transforms;
        }
};

class Color {
    private:
        Point diffuse, ambient, specular, emissive;
        float shininess;
    
    public:
        Point getDiffuse() const {return diffuse;}
        Point getAmbient() const {return ambient;}
        Point getSpecular() const {return specular;}
        Point getEmissive() const {return emissive;}
        float getShininess() const {return shininess;}

        void setDiffuse(float r, float g, float b) {diffuse = Point(r/255, g/255, b/255);}
        void setAmbient(float r, float g, float b) {ambient = Point(r/255, g/255, b/255);}
        void setSpecular(float r, float g, float b) {specular = Point(r/255, g/255, b/255);}
        void setEmissive(float r, float g, float b) {emissive = Point(r/255, g/255, b/255);}
        void setShininess(float shininess) {this->shininess = shininess;}

        void doColor() {
            float diffuse[4] = {this->diffuse.getX(), this->diffuse.getY(), this->diffuse.getZ(), 1},
                  ambient[4] = {this->ambient.getX(), this->ambient.getY(), this->ambient.getZ(), 1},
                  specular[4] = {this->specular.getX(), this->specular.getY(), this->specular.getZ(), 1},
                  emissive[4] = {this->emissive.getX(), this->emissive.getY(), this->emissive.getZ(), 1};
            
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissive);
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
        }

        void printColor() {
            cout << "Diffuse: " << diffuse.getX() << " " << diffuse.getY() << " " << diffuse.getZ() << endl;
            cout << "Ambient: " << ambient.getX() << " " << ambient.getY() << " " << ambient.getZ() << endl;
            cout << "Specular: " << specular.getX() << " " << specular.getY() << " " << specular.getZ() << endl;
            cout << "Emission: " << emissive.getX() << " " << emissive.getY() << " " << emissive.getZ() << endl;
            cout << "Shininess: " << shininess << endl;
        }

        Color() {
            diffuse = Point(200/255, 200/255, 200/255);
            ambient = Point(50/255, 50/255, 50/255);
            specular = Point(0, 0, 0);
            emissive = Point(0, 0, 0);
            shininess = 0;
        }

        Color(Point diffuse, Point ambient, Point specular, Point emission, float shininess) {
            this->diffuse = diffuse;
            this->ambient = ambient;
            this->specular = specular;
            this->emissive = emission;
            this->shininess = shininess;
        }
};

class Model {
    private:
        string file;
        pair<string, vector<Point2D>> textureModel;
        vector<Point> points;
        vector<Point> normals;
        unsigned int* buffers; // ids of vbos
        Color color;

    public:
        string getFileName() const {return file;}
        pair<string, vector<Point2D>> getTextureModel() const {return textureModel;}
        vector<Point> getPoints() const {return points;}
        vector<Point> getNormals() const {return normals;}
        unsigned int* getBuffers() const {return buffers;}
        Color getColor() const {return color;}

        void printModel() {
            cout << "File: " << file << endl;
            cout << "Texture: " << textureModel.first << endl;
            /*for(int i = 0; i < textureModel.second.size(); i++) {
                cout << "Texture " << i << ": " << textureModel.second.at(i).getX() << " " << textureModel.second.at(i).getY() << endl;
            }*/
            cout << "Points: " << endl;
            for (int i = 0; i < points.size(); i++) {
                points.at(i).printPoint();
            }
            cout << "Normals: " << endl;
            for (int i = 0; i < normals.size(); i++) {
                normals.at(i).printPoint();
            }
            cout << "Buffers: " << endl;
            for (int i = 0; i < 3; i++) {
                cout << buffers[i] << endl;
            }
            cout << "Color: " << endl;
            color.printColor();
        }

        Model() {
            this->file = "";
            this->textureModel = pair<string, vector<Point2D>>("", vector<Point2D>());
            this->points = vector<Point>();
            this->normals = vector<Point>();
            this->buffers = new unsigned int[3];
            this->color = Color();
        }

        Model(string file, pair<string, vector<Point2D>> textureModel, vector<Point> points, vector<Point> normals, unsigned int* buffers, Color color) {
            this->file = file;
            this->textureModel = textureModel;
            this->points = points;
            this->normals = normals;
            this->buffers = buffers;
            this->color = color;
        }
};

class Models {
    private:
        vector<Model> models;
    
    public:
        vector<Model> getModels() const {return models;}
        
        void addModel(Model m) {models.push_back(m);}
        
        void printModels() {
            if (models.empty()) {
                cout << "Models vector is empty" << endl;
                return;
            }

            for (int i = 0; i < models.size(); i++) {
                models.at(i).printModel();
            }
        }

        Models() {
            this->models = vector<Model>();
        }

        Models(vector<Model> models) {
            this->models = models;
        }
};

class Group {
    private: 
        Transforms transforms;
        Models models;
        vector<Group> groups;
    
    public:
        Transforms getTransforms() const {return transforms;}
        Models getModels() const {return models;}
        vector<Group> getGroups() const {return groups;}
        
        void addGroup(Group g) {groups.push_back(g);}
        
        void printGroups() {
            cout << "Group transforms: " << endl;
            transforms.printTransforms();
            cout << "Group models: " << endl;
            models.printModels();
            cout << "Group groups: " << endl;
            for (int i = 0; i < groups.size(); i++) {
                groups.at(i).printGroups();
            }
        }

        Group() {
            transforms = Transforms();
            models = Models();
            groups = vector<Group>();
        }

        Group(Transforms transforms, Models models, vector<Group> groups) {
            this->transforms = transforms;
            this->models = models;
            this->groups = groups;
        }
};



class Tree {
    private:
        Window window;
        Camera camera;
        Lights lights;
        Group groups;
        map<string, unsigned int*> modelsVBOs;
        map<string, unsigned int> mapTextures;
    
    public:
        Window getWindow() const {return window;}
        Camera getCamera() const {return camera;}
        Lights getLights() const {return lights;}
        Group getGroup() const {return groups;}
        map<string, unsigned int*> getModelsVBOs() const {return modelsVBOs;}
        map<string, unsigned int> getMapTextures() const {return mapTextures;}

        void printTree() {
            cout << "Window: " << endl;
            window.printWindow();
            cout << "Camera: " << endl;
            camera.printCamera();
            lights.printLights();
            cout << "Groups: " << endl;
            groups.printGroups();
            cout << "Models VBOs: " << endl;
            for (auto it = modelsVBOs.begin(); it != modelsVBOs.end(); it++) {
                cout << "Key: " << it->first << endl;
                cout << "Value: " << it->second << endl;
            }
            cout << "Textures: " << endl;
            /*for (auto it = mapTextures.begin(); it != mapTextures.end(); it++) {
                cout << "Key: " << it->first << endl;
                cout << "Value: " << it->second << endl;
            }*/
        }

        Tree() {
            window = Window();
            camera = Camera();
            lights = Lights();
            groups = Group();
            modelsVBOs = map<string, unsigned int*>();
            mapTextures = map<string, unsigned int>();
        }

        Tree(Window window, Camera camera, Lights lights, Group groups, map<string, unsigned int*> modelsVBOs, map<string, unsigned int> mapTextures) {
            this->window = window;
            this->camera = camera;
            this->lights = lights;
            this->groups = groups;
            this->modelsVBOs = modelsVBOs;  
            this->mapTextures = mapTextures;
        }
};

Tree readXML(const char * path);

#endif