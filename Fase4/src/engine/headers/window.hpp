#ifndef WINDOW_HPP  
#define WINDOW_HPP

#include "../../utils/headers/tinyxml2.hpp"
#include <iostream>

using namespace std;

class Window {
    private:
        int width, height;
    
    public:
        int getWidth() const {return width;}
        int getHeight() const {return height;}

        void printWindow() {
            cout << "Window width: " << getWidth() << endl;
            cout << "Window height: " << getHeight() << endl;
        }

        Window() {
            width = 0;
            height = 0;
        }

        Window(int width, int height) {
            this->width = width;
            this->height = height;
        }
};

Window readWindow(tinyxml2::XMLNode *root);

#endif