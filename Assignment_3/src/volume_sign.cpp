#include "incremental.hpp"

int Volume_Sign(Face f, Vertex p) {

    // std::cout << "In Volume_Sign()\n";
    // Inspect_Face(f);
    // Inspect_Vertex(p);

    double vol;
    double ax, ay, az, bx, by, bz, cx, cy, cz;

    // The sides of the tetrahedron not on the face

    ax = f -> vertex[0] -> v[X] - p -> v[X];
    ay = f -> vertex[0] -> v[Y] - p -> v[Y];
    az = f -> vertex[0] -> v[Z] - p -> v[Z];

    bx = f -> vertex[1] -> v[X] - p -> v[X];
    by = f -> vertex[1] -> v[Y] - p -> v[Y];
    bz = f -> vertex[1] -> v[Z] - p -> v[Z];

    cx = f -> vertex[2] -> v[X] - p -> v[X];
    cy = f -> vertex[2] -> v[Y] - p -> v[Y];
    cz = f -> vertex[2] -> v[Z] - p -> v[Z];

    // The expansion of the volume determinant
    
    vol = ax * (by * cz - bz * cy) + ay * (bz * cx - bx * cz) + az * (bx * cy - by * cx);

    // std::cout << "The volume is " << vol << "\n";

    if (vol > 0.5)
        return 1;
    else if (vol < -0.5)
        return -1;
    else
        return 0;
        
}