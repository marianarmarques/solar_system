#include "headers/box.hpp"

map<int, vector<Point>> Box::point_generator() {

    vector<Point> points = vector<Point>(), normals = vector<Point>();

    float size = length / (float)grid;
    float h_size = length / 2.0;
    float px = 0, pz = 0, px2 = 0, pz2 = 0;

    for(int i = 0; i < grid; i++) {
        for(int j = 0; j < grid; j++) {

            px = -h_size + (size * j);      // x à esquerda <- num plano 2D
            pz = h_size - (size * i);       // z a baixo    <- num plano 2D
            px2 = -h_size + (size * (j+1)); // x à direita  <- num plano 2D
            pz2 = h_size - (size * (i+1));  // z a cima     <- num plano 2D



            // Base superior
            Point p11 = Point(px, h_size, pz2);
            Point p12 = Point(px, h_size, pz);
            Point p13 = Point(px2, h_size, pz);
            Point p14 = Point(px2, h_size, pz2);

            // Calculate normal for 1st triangle

            Point v11 = Point(), v12 = Point(), normal11 = Point(), normal12 = Point(), normal13 = Point(), normal14 = Point();
           
            v11.subPoints(&p11, &p12);
            v12.subPoints(&p11, &p13);
            normal11.cross(&v11, &v12);
            normal11.normalize();

            
            v11.subPoints(&p12, &p13);
            v12.subPoints(&p12, &p14);
            normal12.cross(&v11, &v12);
            normal12.normalize();
            
            v11.subPoints(&p13, &p14);
            v12.subPoints(&p13, &p11);
            normal13.cross(&v11, &v12);
            normal13.normalize();

            v11.subPoints(&p14, &p11);
            v12.subPoints(&p14, &p12);
            normal14.cross(&v11, &v12);
            normal14.normalize();

            // 1st triangle
            points.push_back(p11);
            points.push_back(p12);
            points.push_back(p13);

            normals.push_back(normal11);
            normals.push_back(normal12);
            normals.push_back(normal13);

            // 2nd triangle
            points.push_back(p13);
            points.push_back(p14);
            points.push_back(p11);

            normals.push_back(normal13);
            normals.push_back(normal14);
            normals.push_back(normal11);



            // Base inferior
            Point p21 = Point(px2, -h_size, pz);
            Point p22 = Point(px, -h_size, pz);
            Point p23 = Point(px, -h_size, pz2);
            Point p24 = Point(px2, -h_size, pz2);

            // Calculate normal for 1st triangle

            Point v21 = Point(), v22 = Point(), normal21 = Point(), normal22 = Point(), normal23 = Point(), normal24 = Point();
            v21.subPoints(&p21, &p22);
            v22.subPoints(&p21, &p23);
            normal21.cross(&v21, &v22);
            normal21.normalize();

            v21.subPoints(&p22, &p23);
            v22.subPoints(&p22, &p24);
            normal22.cross(&v21, &v22);
            normal22.normalize();

            v21.subPoints(&p23, &p21);
            v22.subPoints(&p23, &p24);
            normal23.cross(&v21, &v22);
            normal23.normalize();

            v21.subPoints(&p24, &p21);
            v22.subPoints(&p24, &p22);
            normal24.cross(&v21, &v22);
            normal24.normalize();

            // 1st triangle
            points.push_back(p21);
            points.push_back(p22);
            points.push_back(p23);

            normals.push_back(normal21);
            normals.push_back(normal22);
            normals.push_back(normal23);

            // 2nd triangle
            points.push_back(p23);
            points.push_back(p24);
            points.push_back(p21);

            normals.push_back(normal23);
            normals.push_back(normal24);
            normals.push_back(normal21);



            // Lateral 1 - virada para a frente
            Point p31 = Point(-h_size, px, pz2);
            Point p32 = Point(-h_size, px, pz);
            Point p33 = Point(-h_size, px2, pz);
            Point p34 = Point(-h_size, px2, pz2);

            // Calculate normal for 1st triangle

            Point v31 = Point(), v32 = Point(), normal31 = Point(), normal32 = Point(), normal33 = Point(), normal34 = Point();
            
            v31.subPoints(&p31, &p32);
            v32.subPoints(&p31, &p33);
            normal31.cross(&v31, &v32);
            normal31.normalize();
            
            v31.subPoints(&p32, &p33);
            v32.subPoints(&p32, &p34);
            normal32.cross(&v31, &v32);
            normal32.normalize();
            
            v31.subPoints(&p33, &p34);
            v32.subPoints(&p33, &p31);
            normal33.cross(&v31, &v32);
            normal33.normalize();
            
            v31.subPoints(&p34, &p31);
            v32.subPoints(&p34, &p32);
            normal34.cross(&v31, &v32);
            normal34.normalize();
               
            // 1st triangle
            points.push_back(p31);
            points.push_back(p32);
            points.push_back(p33);

            normals.push_back(normal31);
            normals.push_back(normal32);
            normals.push_back(normal33);

            // 2nd triangle
            points.push_back(p33);
            points.push_back(p34);
            points.push_back(p31);

            normals.push_back(normal33);
            normals.push_back(normal34);
            normals.push_back(normal31);



            // Lateral 2 - virada para trás
            Point p41 = Point(h_size, px2, pz);
            Point p42 = Point(h_size, px, pz);
            Point p43 = Point(h_size, px, pz2);
            Point p44 = Point(h_size, px2, pz2);

            // Calculate normal for 1st triangle

            Point v41 = Point(), v42 = Point(), normal41 = Point(), normal42 = Point(), normal43 = Point(), normal44 = Point();
            
            v41.subPoints(&p41, &p42);
            v42.subPoints(&p41, &p43);
            normal41.cross(&v41, &v42);
            normal41.normalize();
            
            v41.subPoints(&p42, &p43);
            v42.subPoints(&p42, &p44);
            normal42.cross(&v41, &v42);
            normal42.normalize();
            
            v41.subPoints(&p43, &p44);
            v42.subPoints(&p43, &p41);
            normal43.cross(&v41, &v42);
            normal43.normalize();
            
            v42.subPoints(&p44, &p42);
            normal44.cross(&v41, &v42);
            normal44.normalize();
            
            // 1st triangle
            points.push_back(p41);
            points.push_back(p42);
            points.push_back(p43);

            normals.push_back(normal41);
            normals.push_back(normal42);
            normals.push_back(normal43);

            // 2nd triangle
            points.push_back(p43);
            points.push_back(p44);
            points.push_back(p41);

            normals.push_back(normal43);
            normals.push_back(normal44);
            normals.push_back(normal41);



            // Lateral 3 - virada para a esquerda
            Point p51 = Point(px, pz2, -h_size);
            Point p52 = Point(px, pz, -h_size);
            Point p53 = Point(px2, pz, -h_size);
            Point p54 = Point(px2, pz2, -h_size);

            // Calculate normal for 1st triangle

            Point v51 = Point(), v52 = Point(), normal51 = Point(), normal52 = Point(), normal53 = Point(), normal54 = Point();
           
            v51.subPoints(&p51, &p52);
            v52.subPoints(&p51, &p53);
            normal51.cross(&v51, &v52);
            normal51.normalize();
        
            v51.subPoints(&p52, &p53);
            v52.subPoints(&p52, &p54);
            normal52.cross(&v51, &v52);
            normal52.normalize();
            
            v51.subPoints(&p53, &p54);
            v52.subPoints(&p53, &p51);
            normal53.cross(&v51, &v52);
            normal53.normalize();
            
            v51.subPoints(&p54, &p51);
            v52.subPoints(&p54, &p52);
            normal54.cross(&v51, &v52);
            normal54.normalize();
                
            // 1st triangle
            points.push_back(p51);
            points.push_back(p52);
            points.push_back(p53);

            normals.push_back(normal51);
            normals.push_back(normal52);
            normals.push_back(normal53);

            // 2nd triangle
            points.push_back(p53);
            points.push_back(p54);
            points.push_back(p51);

            normals.push_back(normal53);
            normals.push_back(normal54);
            normals.push_back(normal51);
            


            // Lateral 4 - virada para a direita
            Point p61 = Point(px2, pz, h_size);
            Point p62 = Point(px, pz, h_size);
            Point p63 = Point(px, pz2, h_size);
            Point p64 = Point(px2, pz2, h_size);

            // Calculate normal for 1st triangle

            Point v61 = Point(), v62 = Point(), normal61 = Point(), normal62 = Point(), normal63 = Point(), normal64 = Point();

            v61.subPoints(&p61, &p62);
            v62.subPoints(&p61, &p63);
            normal61.cross(&v61, &v62);
            normal61.normalize();
            
            v61.subPoints(&p62, &p63);
            v62.subPoints(&p62, &p64);
            normal62.cross(&v61, &v62);
            normal62.normalize();
            
            v61.subPoints(&p63, &p64);
            v62.subPoints(&p63, &p61);
            normal63.cross(&v61, &v62);
            normal63.normalize();
            
            v61.subPoints(&p64, &p61);
            v62.subPoints(&p64, &p62);
            normal64.cross(&v61, &v62);
            normal64.normalize();
            
            // 1st triangle
            points.push_back(p61);
            points.push_back(p62);
            points.push_back(p63);

            normals.push_back(normal61);
            normals.push_back(normal62);
            normals.push_back(normal63);

            // 2nd triangle
            points.push_back(p63);
            points.push_back(p64);
            points.push_back(p61);

            normals.push_back(normal63);
            normals.push_back(normal64);
            normals.push_back(normal61);
        }
    }

    return {{0, points}, {1, normals}};
}