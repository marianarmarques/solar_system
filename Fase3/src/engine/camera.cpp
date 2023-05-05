#include "headers/camera.hpp"

static float alpha, betha, radius;

Camera readCamera(tinyxml2::XMLNode *world)
{
    if(!world->FirstChildElement("camera")) {
        return Camera();
    }

    Point position(stof(world->FirstChildElement("camera")->FirstChildElement("position")->Attribute("x")),
                   stof(world->FirstChildElement("camera")->FirstChildElement("position")->Attribute("y")),
                   stof(world->FirstChildElement("camera")->FirstChildElement("position")->Attribute("z")));

    Point lookAt(stof(world->FirstChildElement("camera")->FirstChildElement("lookAt")->Attribute("x")),
                 stof(world->FirstChildElement("camera")->FirstChildElement("lookAt")->Attribute("y")),
                 stof(world->FirstChildElement("camera")->FirstChildElement("lookAt")->Attribute("z")));

    Point up(stof(world->FirstChildElement("camera")->FirstChildElement("up")->Attribute("x")),
             stof(world->FirstChildElement("camera")->FirstChildElement("up")->Attribute("y")),
             stof(world->FirstChildElement("camera")->FirstChildElement("up")->Attribute("z")));

    Point projection(stof(world->FirstChildElement("camera")->FirstChildElement("projection")->Attribute("fov")),
                     stof(world->FirstChildElement("camera")->FirstChildElement("projection")->Attribute("near")),
                     stof(world->FirstChildElement("camera")->FirstChildElement("projection")->Attribute("far")));

    return Camera(position, up, lookAt, projection);
}