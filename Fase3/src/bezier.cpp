#include "headers/bezier.hpp"

void Bezier::parsePatch() {
    string filename = "../3DFiles/" + file;
    ifstream file(filename);
    string line;

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    getline(file, line);
    int numPatches = atoi(line.c_str());
    
    map<int, vector<int>> ind = map<int, vector<int>>();
    for(int i = 0; i < numPatches; i++) {
        getline(file, line);
        stringstream ss(line);
        string token;
        vector<int> v = vector<int>();
    
        while(getline(ss, token, ',')) {
            v.push_back(stoi(token));
        }

        ind.insert(pair<int, vector<int>>(i, v));
    }

    getline(file, line);
    int numPoints = atoi(line.c_str());

    vector<Point> points = vector<Point>();
    for(int i = 0; i < numPoints; i++) {
        getline(file, line);
        stringstream ss(line);
        float x, y, z;
        char c;
        
        ss >> x >> c >> y >> c >> z;
        
        points.push_back(Point(x, y, z));
    }

    for (auto it = ind.begin(); it != ind.end(); it++) {
        vector<Point> v = vector<Point>();
       
        for (int i = 0; i < it->second.size(); i++) {
            v.push_back(points.at(it->second.at(i)));
        }

        patches.insert(pair<int, vector<Point>>(it->first, v));
    }
}

Point Bezier::getBezierPoint(int p, float u, float v) {

    float m[4][4] = {{-1.0f, +3.0f, -3.0f, +1.0f},
                     {+3.0f, -6.0f, +3.0f, +0.0f},
                     {-3.0f, +3.0f, +0.0f, +0.0f},
                     {+1.0f, +0.0f, +0.0f, +0.0f}};


    float bu[4] = {powf(u,3),powf(u,2),u,1};
    float bv[4] = {powf(v,3),powf(v,2),v,1};
    
    float points_x[4][4];
    float points_y[4][4];
    float points_z[4][4];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            points_x[i][j] = patches.at(p).at(i * 4 + j).getX();
            points_y[i][j] = patches.at(p).at(i * 4 + j).getY();
            points_z[i][j] = patches.at(p).at(i * 4 + j).getZ();
        }
    }
    
    // bezier function
    float res_u[4], res_v[4];
    utils::multMatrixVector(*m, bu, res_u);
    utils::multMatrixVector(*m, bv, res_v);

    // res * points
    float res_x[4],res_y[4],res_z[4];
    utils::multVectorMatrix(res_u, *points_x, res_x);
    utils::multVectorMatrix(res_u, *points_y, res_y);
    utils::multVectorMatrix(res_u, *points_z, res_z);

    float x = utils::multVectors(res_x, res_v);
    float y = utils::multVectors(res_y, res_v);
    float z = utils::multVectors(res_z, res_v);

    Point ponto = Point(x, y, z);
    return ponto;

}

vector<Point> Bezier::point_generator() {
    vector<Point> points = vector<Point>();

    parsePatch();

    for(auto it = patches.begin(); it != patches.end(); it++) {

        for(int tv = 0; tv < tessellation; tv++) {
            float v = (float) tv/tessellation;

            for(int tu = 0; tu < tessellation; tu++) {
                float u = (float) tu/tessellation;

                 // triângulo superior
                points.push_back(getBezierPoint(it->first, (u + (1.0f/tessellation)), (v + (1.0f/tessellation))));
                points.push_back(getBezierPoint(it->first, u, (v + (1.0f/tessellation))));
                points.push_back(getBezierPoint(it->first, u, v));
                // triângulo inferio
                points.push_back(getBezierPoint(it->first, u, v));
                points.push_back(getBezierPoint(it->first, (u + (1.0f/tessellation)), v));
                points.push_back(getBezierPoint(it->first, (u + (1.0f/tessellation)), (v + (1.0f/tessellation))));
            }
        }
    }

    return points;
}