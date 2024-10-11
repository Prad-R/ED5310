#include "incremental.hpp"

void Double_Triangle() {

    // std::cout << "In Double_Triangle()\n";

    Vertex v0, v1, v2, v3, t;
    Face f0, f1 = NULL;
    Edge e0, e1, e2, s;
    int vol;

    // Finding 3 non-collinear points

    v0 = vertices;
    while (Collinear(v0, v0 -> next, v0 -> next -> next))
        if ((v0 = v0 -> next) == vertices) {

            std::cout << "Double_Triangle() : All points are collinear!\n";
            exit(0);

        }
    
    v1 = v0 -> next;
    v2 = v1 -> next;

    // Marking the points as processed

    v0 -> mark = PROCESSED;
    v1 -> mark = PROCESSED;
    v2 -> mark = PROCESSED;

    // Creating the two twin faces of the double triangle polytope

    f0 = Make_Face(v0, v1, v2, f1);
    f1 = Make_Face(v2, v1, v0, f0);
    
    // Linking the adjacent face fields

    f0 -> edge[0] -> adjface[1] = f1;
    f0 -> edge[1] -> adjface[1] = f1;
    f0 -> edge[2] -> adjface[1] = f1;
    f1 -> edge[0] -> adjface[1] = f0;
    f1 -> edge[1] -> adjface[1] = f0;
    f1 -> edge[2] -> adjface[1] = f0;

    // Finding a fourth non-collinear point to form a tetrahedron

    v3 = v2 -> next;
    vol = Volume_Sign(f0, v3);

    while (!vol) {

        if ((v3 = v3 -> next) == v0) {

            std::cout << "Double_Triangle() : All points are coplanar!\n";
            exit(0);

        }

        vol = Volume_Sign(f0, v3);

    }

    // Ensuring v3 will be the first point added

    vertices = v3;

}