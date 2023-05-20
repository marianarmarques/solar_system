#include "headers/light.hpp"

Lights readLights(tinyxml2::XMLNode *root) {

    Lights ls = Lights();

    tinyxml2::XMLElement *lights = root->FirstChildElement("lights");
    if (!lights) return ls;

    tinyxml2::XMLElement *light = lights->FirstChildElement("light");

    while(light) {
        int id = ls.getLights().size();

        if(!strcmp(light->Attribute("type"), "point")) {
            float posx, posy, posz;
            light->QueryFloatAttribute("posx", &posx);
            light->QueryFloatAttribute("posy", &posy);
            light->QueryFloatAttribute("posz", &posz);

            PointLight *pl = new PointLight(id, Point(posx, posy, posz));
            ls.addLight(pl);
        }
        
        if(!strcmp(light->Attribute("type"), "directional")) {
            float dirx, diry, dirz;
            light->QueryFloatAttribute("dirx", &dirx);
            light->QueryFloatAttribute("diry", &diry);
            light->QueryFloatAttribute("dirz", &dirz);
       
            DirectionalLight *dl = new DirectionalLight(id, Point(dirx, diry, dirz));
            ls.addLight(dl);
        }
        
        if(!strcmp(light->Attribute("type"), "spot")) {
            float posx, posy, posz, dirx, diry, dirz, cutoff;
            light->QueryFloatAttribute("posx", &posx);
            light->QueryFloatAttribute("posy", &posy);
            light->QueryFloatAttribute("posz", &posz);
            light->QueryFloatAttribute("dirx", &dirx);
            light->QueryFloatAttribute("diry", &diry);
            light->QueryFloatAttribute("dirz", &dirz);
            light->QueryFloatAttribute("cutoff", &cutoff);

            SpotLight *sl = new SpotLight(id, Point(posx, posy, posz), Point(dirx, diry, dirz), cutoff);
            ls.addLight(sl);
        }

        light = light->NextSiblingElement();
    }
    
    return ls;
}