#include "headers/group.hpp"

map<string, pair<unsigned int,unsigned int>> modelsVBOs = map<string, pair<unsigned int,unsigned int>>(); 

void Translation::getCatmullRomPoint(float t, Point p1, Point p2, Point p3, Point p4, Point *pos, Point *deriv) {
    
    // catmull-rom matrix
	float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
						{ 1.0f, -2.5f,  2.0f, -0.5f},
						{-0.5f,  0.0f,  0.5f,  0.0f},
						{ 0.0f,  1.0f,  0.0f,  0.0f}};

    float px[4] = {p1.getX(), p2.getX(), p3.getX(), p4.getX()};
    float py[4] = {p1.getY(), p2.getY(), p3.getY(), p4.getY()};
    float pz[4] = {p1.getZ(), p2.getZ(), p3.getZ(), p4.getZ()};

    float ax[4], ay[4], az[4];
    utils::multMatrixVector(*m, px, ax);
    utils::multMatrixVector(*m, py, ay);
    utils::multMatrixVector(*m, pz, az);

    // catmull-rom function > pos = T * A -> pos[i] = at³ + bt² + ct + d
    pos->setX(powf(t,3.0) * ax[0] + powf(t,2.0) * ax[1] + t * ax[2] + ax[3]);
    pos->setY(powf(t,3.0) * ay[0] + powf(t,2.0) * ay[1] + t * ay[2] + ay[3]);
    pos->setZ(powf(t,3.0) * az[0] + powf(t,2.0) * az[1] + t * az[2] + az[3]);

    // catmull-rom derivative > deriv = T' * A -> deriv[i] = 3at² + 2bt + c
    deriv->setX(3 * powf(t,2.0) * ax[0] + 2 * t * ax[1] + ax[2]);
    deriv->setY(3 * powf(t,2.0) * ay[0] + 2 * t * ay[1] + ay[2]);
    deriv->setZ(3 * powf(t,2.0) * az[0] + 2 * t * az[1] + az[2]);
}

void Translation::getGlobalCatmullRomPoint(float gt, Point *pos, Point *deriv) {
    int size = points.size();
    float tCatmull = gt * size; // this is the real global t
    int index = floor(tCatmull);  // which segment
    tCatmull -= index; // where within  the segment

    int ind[4];
    ind[0] = (index + size-1) % size;	
    ind[1] = (ind[0]+1) % size;
    ind[2] = (ind[1]+1) % size; 
    ind[3] = (ind[2]+1) % size;

    getCatmullRomPoint(tCatmull, points[ind[0]], points[ind[1]], points[ind[2]], points[ind[3]], pos, deriv);
}

void Translation::renderCatmullRoomCurve() {
    float gt = 0;
    Point pos = Point(), deriv = Point();

    glBegin(GL_LINE_LOOP);
    while (gt < 1) {
        getGlobalCatmullRomPoint(gt, &pos, &deriv);
        glVertex3f(pos.getX(), pos.getY(), pos.getZ());
        gt += 0.001;
    }
    glEnd();
}

void Translation::alignModel(Point *deriv) {
    Point * up = new Point(0,1,0);
    Point * deriv_cross = new Point(); 
    
    utils::normalize(deriv);

    utils::cross(deriv, up, deriv_cross);
    
    utils::normalize(deriv_cross);
    
    utils::cross(deriv_cross, deriv, up);
    
    utils::normalize(up);
    
    // Rotation matrix
    float m[4][4] = {{deriv->getX(), deriv->getY(), deriv->getZ(), 0},
                     {up->getX(), up->getY(), up->getZ(), 0},
                     {deriv_cross->getX(), deriv_cross->getY(), deriv_cross->getZ(), 0},
                     {0, 0, 0, 1}};

    glMultMatrixf((float *) m);
}

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
            float time = -1;
            bool align = 0;
            vector<Point> points = vector<Point>();
            
            Translation *t = new Translation();

            if(transformation->QueryFloatAttribute("time", &time));
            if(transformation->QueryBoolAttribute("align", &align));

            tinyxml2::XMLElement *point = transformation->FirstChildElement("point");
            while(point)
            {
                float x, y, z;
                point->QueryFloatAttribute("x", &x);
                point->QueryFloatAttribute("y", &y);
                point->QueryFloatAttribute("z", &z);

                points.push_back(Point(x, y, z));
                point = point->NextSiblingElement("point");
            }

            if(time == -1) {
                float x, y, z;
                transformation->QueryFloatAttribute("x", &x);
                transformation->QueryFloatAttribute("y", &y);
                transformation->QueryFloatAttribute("z", &z);

                t = new Translation(x, y, z);
            }
            else {
                t = new Translation(time, align, points);
            }
                
            transforms.addTransform(*t);
        }

        if (!strcmp(transformation->Name(), "rotate"))
        {
            float angle = 0, time = -1, x, y, z;

            if(transformation->QueryFloatAttribute("angle", &angle));
            if(transformation->QueryFloatAttribute("time", &time));

            transformation->QueryFloatAttribute("x", &x);
            transformation->QueryFloatAttribute("y", &y);
            transformation->QueryFloatAttribute("z", &z);

            Rotation *r = new Rotation(angle, time, x, y, z);
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
