#include "incremental.hpp"

// To find normal, take cross product of ba with bc and normalize

float* Find_Normal(int a[3], int b[3], int c[3]) {

    int side_ba[3], side_bc[3];
    static float normal[3];

    for (int i = 0; i < 3; i ++) {

        side_ba[i] = a[i] - b[i];
        side_bc[i] = c[i] - b[i]; 

    }

    normal[X] = side_bc[Y] * side_ba[Z] - side_bc[Y] * side_ba[Z];
    normal[Y] = side_ba[X] * side_bc[Z] - side_bc[X] * side_ba[Z];
    normal[Z] = side_bc[X] * side_ba[Y] - side_ba[X] * side_bc[Y];

    float mag = sqrt(normal[X] * normal[X] + normal[Y] * normal[Y] + normal[Z] * normal[Z]);

    normal[X] = normal[X] / mag;
    normal[Y] = normal[Y] / mag;
    normal[Z] = normal[Z] / mag;

    return normal;
}

void Write_STL() {

    Face f = faces;
    int a[3], b[3], c[3];
    float n[3];

    std::ofstream file("src/stl_files/hull.stl", std::ios::out|std::ios::app);

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    }

    file << "solid Convex_Hull\n";

    do {

            a[X] = f -> vertex[0] -> v[X];
            a[Y] = f -> vertex[0] -> v[Y];
            a[Z] = f -> vertex[0] -> v[Z];

            b[X] = f -> vertex[1] -> v[X];
            b[Y] = f -> vertex[1] -> v[Y];
            b[Z] = f -> vertex[1] -> v[Z];

            c[X] = f -> vertex[2] -> v[X];
            c[Y] = f -> vertex[2] -> v[Y];
            c[Z] = f -> vertex[2] -> v[Z];

            float* normal = Find_Normal(a, b, c);

            n[X] = normal[0];
            n[Y] = normal[1];
            n[Z] = normal[2];

            file << "facet normal " << n[X] << " " << n[Y] << " " << n[Z] << "\n";
            file << "   outer loop\n";

            file << "       vertex " << a[X] << " " << a[Y] << " " << a[Z] << "\n";
            file << "       vertex " << b[X] << " " << b[Y] << " " << b[Z] << "\n";
            file << "       vertex " << c[X] << " " << c[Y] << " " << c[Z] << "\n";

            file << "   endloop\n";
            file << "endfacet\n";


        f = f -> next;

    } while (f != faces);

    file << "endsolid Convex_Hull\n";

    file.close();

}