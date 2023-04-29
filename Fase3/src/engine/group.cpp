#include "headers/group.hpp"

map<string, pair<unsigned int,unsigned int>> modelsVBOs = map<string, pair<unsigned int,unsigned int>>(); 

Transforms readTransforms(tinyxml2::XMLNode *group)
{
    Transforms transforms = Transforms();

    tinyxml2::XMLElement *transform = group->FirstChildElement("transform");
    if (!transform)
    {
        return transforms;
    }

    tinyxml2::XMLElement *transformation = transform->FirstChildElement();

    while (transformation)
    {
        if (!strcmp(transformation->Name(), "translate"))
        {
            float time;
            bool align;
            vector<Point> points = vector<Point>();

            transformation->QueryFloatAttribute("time", &time);
            transformation->QueryBoolAttribute("align", &align);

            tinyxml2::XMLElement *point = transformation->FirstChildElement("point");
            while(point)
            {
                float x, y, z;
                point->QueryFloatAttribute("x", &x);
                point->QueryFloatAttribute("y", &y);
                point->QueryFloatAttribute("z", &z);

                points.push_back(Point(x, y, z));
                point = point->NextSiblingElement();
            }

            Translation *t = new Translation(time, align, points);
            transforms.addTransform(*t);
        }

        if (!strcmp(transformation->Name(), "rotate"))
        {
            float time, x, y, z;
            transformation->QueryFloatAttribute("time", &time);
            transformation->QueryFloatAttribute("x", &x);
            transformation->QueryFloatAttribute("y", &y);
            transformation->QueryFloatAttribute("z", &z);

            Rotation *r = new Rotation(time, x, y, z);
            transforms.addTransform(*r);
        }

        if (strcmp(transformation->Name(), "scale") == 0)
        {
            float x, y, z;
            transformation->QueryFloatAttribute("x", &x);
            transformation->QueryFloatAttribute("y", &y);
            transformation->QueryFloatAttribute("z", &z);

            Scale *s = new Scale(x, y, z);
            transforms.addTransform(*s);
        }

        transformation = transformation->NextSiblingElement();
    }

    return transforms;
}

vector<Point> *readPoints(const char *path)
{
    float x, y, z;
    vector<Point> *points = new vector<Point>();

    ifstream file(path);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return points;
    }

    while (file >> x >> y >> z)
    {
        points->push_back(Point(x, y, z));
    }

    return points;
}

Models readModels(tinyxml2::XMLNode *group)
{
    Models models = Models();

    tinyxml2::XMLElement *ms = group->FirstChildElement("models");
    if (!ms)
    {
        return models;
    }

    tinyxml2::XMLElement *m = ms->FirstChildElement("model");

    while (m)
    {
        std::string file = m->ToElement()->Attribute("file");
        vector<Point> *vectorPoints = readPoints(("../3DFiles/" + file).c_str());

        if(modelsVBOs.find(file) != modelsVBOs.end()) { // IF ALREADY EXISTS
            models.addModel(Model(file, vectorPoints, modelsVBOs.find(file)->second));
            m = m->NextSiblingElement("model");
            
            continue; 
        }

        unsigned int mapSize = modelsVBOs.size();
        modelsVBOs.insert(pair<string, pair<unsigned int, unsigned int>>(file, pair<unsigned int, unsigned int>(mapSize, vectorPoints->size())));

        auto modelVBOs = modelsVBOs.find(file);
        //printf("MODEL VBO: %s %d %d\n", modelVBOs->first.c_str(), modelVBOs->second.first, modelVBOs->second.second);

        glGenBuffers(1, &modelVBOs->second.first);

        glBindBuffer(GL_ARRAY_BUFFER, modelVBOs->second.first);

        glBufferData(
            GL_ARRAY_BUFFER, // TYPE
            sizeof(float) * vectorPoints->size() * 3, // SIZE VECTOR IN BYTES
            vectorPoints->data(), // VECTOR DATA
            GL_STATIC_DRAW); // USAGE

        models.addModel(Model(file, vectorPoints, modelVBOs->second));

        m = m->NextSiblingElement("model");
    }

    return models;
}

Group readGroups(tinyxml2::XMLNode *group)
{
    Transforms t = readTransforms(group);
    Models m = readModels(group);
    vector<Group> groups = vector<Group>();
    Color c = Color();
    
    tinyxml2::XMLElement *color = group->FirstChildElement("color");
    if(color) {
        c = Color(color->IntAttribute("r"), color->IntAttribute("g"), color->IntAttribute("b"));
    }
    
    tinyxml2::XMLElement *subGroup = group->FirstChildElement("group");
    while (subGroup)
    {
        groups.push_back(readGroups(subGroup));
        subGroup = subGroup->NextSiblingElement("group");
    }

    return Group(t, m, groups, c);
}

Tree readXML(const char *path)
{
    tinyxml2::XMLDocument doc;

    doc.LoadFile(path);
    if (doc.ErrorID())
    {
        printf("%s\n", doc.ErrorStr());
        exit(0);
    }

    tinyxml2::XMLNode *world = doc.FirstChildElement("world");
    if (world == NULL)
        exit(0);
    
    tinyxml2::XMLElement *group = world->FirstChildElement("group");

    return Tree(readWindow(world), readCamera(world), readGroups(group), modelsVBOs);
}
