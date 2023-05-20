#include "headers/window.hpp"

Window readWindow(tinyxml2::XMLNode *world)
{
    if(!world->FirstChildElement("window")) {
        return Window();
    }

    int width = world->FirstChildElement("window")->IntAttribute("width");
    int height = world->FirstChildElement("window")->IntAttribute("height");

    return Window(width, height);
}