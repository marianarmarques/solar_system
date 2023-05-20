#include "headers/camera.hpp"

void Camera::moveCamera(){
    position.setX(radius * cos(betha) * sin(alpha));
    position.setY(radius * sin(betha));
    position.setZ(radius * cos(betha) * cos(alpha));  
}

void Camera::convertToSpherical() {

    if (position.getX() == 0) position.setX(0.0000001);
    if (position.getY() == 0) position.setY(0.0000001);
    if (position.getZ() == 0) position.setZ(0.0000001);

    alpha = atan(position.getX() / position.getZ());
    betha = tan((position.getY() * sin(alpha)) / position.getX());

    if (betha >= M_PI / 2) betha -= M_PI;
    if (betha <= -M_PI / 2) betha += M_PI;

    radius = position.getY() / sin(betha);
}

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

    return Camera(position, up, lookAt, projection, 0, 0, 0);
}