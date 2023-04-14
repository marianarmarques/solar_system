#ifndef POINT_HEADER
#define POINT_HEADER

#include <string>
#include <sstream>

using namespace std;

class Point {
    private:
        float x, y, z;
    
    public:
        float getX() const {return x;}
        float getY() const {return y;}
        float getZ() const {return z;}
        
        void setX(float x) {this->x = x;}
        void setY(float y) {this->y = y;}
        void setZ(float z) {this->z = z;}
        
        string toString() {
            ostringstream point;                // Criação da stream
            point << x << ' ' << y << ' ' << z; // Preenchimento da stream
            return point.str();                 // Extração do conteúdo da stream
        }

        Point () {
            x = 0;
            y = 0;
            z = 0;
        }

        Point(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

#endif