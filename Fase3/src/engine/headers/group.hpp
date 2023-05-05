#ifndef GROUP_HPP
#define GROUP_HPP

#include <GL/glew.h>
#include "GL/glut.h"
#include "../../utils/headers/tinyxml2.hpp"
#include "../../utils/headers/point.hpp"
#include "../../utils/headers/utils.hpp"
#include "window.hpp"
#include "camera.hpp"
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
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

class Model {
    private:
        string file;
        vector<Point>* points;
        pair<unsigned int, unsigned int> pairVBOs;
    
    public:
        std::string getFile() const {return file;}
        vector<Point>* getPoints() const {return points;}
        pair<unsigned int, unsigned int> getPair() const {return pairVBOs;}
        
        void printModel() {
            cout << "Model file: " << getFile() << endl;
            cout << "Model points: " << endl;
            for (int i = 0; i < points->size(); i++) {
                cout << points->at(i).getX() << " " << points->at(i).getY() << " " << points->at(i).getZ() << endl;
            }
            cout << "Model index: " << getPair().first << " " << getPair().second << endl;
        }

        Model() {
            file = "";
            points = new vector<Point>();
            pairVBOs = make_pair(-1, -1);
        }

        Model(std::string file, vector<Point>* points, pair<unsigned int, unsigned int> pairVBOs) {
            this->file = file;
            this->points = points;
            this->pairVBOs = pairVBOs;
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

class Color {
    private:
        float r;
        float g;
        float b;
    
    public:
        float getR() const {return r;}
        float getG() const {return g;}
        float getB() const {return b;}

        void printColor() {
            cout << "Color: " << getR() << " " << getG() << " " << getB() << endl;
        }

        Color() {
            r = 1;
            g = 1;
            b = 1;
        }

        Color(float r, float g, float b) {
            this->r = r / 255;
            this->g = g / 255;
            this->b = b / 255;
        }
};

class Group {
    private: 
        Transforms transforms;
        Models models;
        vector<Group> groups;
        Color color;
    
    public:
        Transforms getTransforms() const {return transforms;}
        Models getModels() const {return models;}
        vector<Group> getGroups() const {return groups;}
        Color getColor() const {return color;}  
        
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
            color = Color();
        }

        Group(Transforms transforms, Models models, vector<Group> groups, Color color) {
            this->transforms = transforms;
            this->models = models;
            this->groups = groups;
            this->color = color;
        }
};

class Tree {
    private:
        Window window;
        Camera camera;
        Group groups;
        map<string, pair<unsigned int,unsigned int>> modelsVBOs;
    
    public:
        Window getWindow() const {return window;}
        Camera getCamera() const {return camera;}
        Group getGroup() const {return groups;}
        map<string, pair<unsigned int,unsigned int>> getModelsVBOs() const {return modelsVBOs;}

        void printTree() {
            cout << "Window: " << endl;
            window.printWindow();
            cout << "Camera: " << endl;
            camera.printCamera();
            cout << "Groups: " << endl;
            groups.printGroups();
            cout << "Models VBOs: " << endl;
            for (auto it = modelsVBOs.begin(); it != modelsVBOs.end(); it++) {
                cout << it->first << " " << it->second.first << " " << it->second.second << endl;
            }
        }

        Tree() {
            window = Window();
            camera = Camera();
            groups = Group();
            map<string, pair<unsigned int,unsigned int>> modelsVBOs = map<string, pair<unsigned int,unsigned int>>();
        }

        Tree(Window window, Camera camera, Group groups, map<string, pair<unsigned int,unsigned int>> modelsVBOs) {
            this->window = window;
            this->camera = camera;
            this->groups = groups;
            this->modelsVBOs = modelsVBOs;
        }
};

Tree readXML(const char * path);

#endif