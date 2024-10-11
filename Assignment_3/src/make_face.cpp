#include "incremental.hpp"

Face Make_Face(Vertex v0, Vertex v1, Vertex v2, Face fold) {

    // std::cout << "In Make_Face()\n";

    Face f;
    Edge e0, e1, e2;

    // Create edges of the triangle

    if (!fold) {

        e0 = Make_Null_Edge();
        e1 = Make_Null_Edge();
        e2 = Make_Null_Edge();

    }
    else {

        // Copy from fold in reverse order

        e0 = fold -> edge[2];
        e1 = fold -> edge[1];
        e2 = fold -> edge[0];

    }

    e0 -> endpts[0] = v0;
    e0 -> endpts[1] = v1;
    e1 -> endpts[0] = v1;
    e1 -> endpts[1] = v2;
    e2 -> endpts[0] = v2;
    e2 -> endpts[1] = v0;

    // Creating face for triangle

    f = Make_Null_Face();

    f -> edge[0] = e0;
    f -> edge[1] = e1;
    f -> edge[2] = e2;
    f -> vertex[0] = v0;
    f -> vertex[1] = v1;
    f -> vertex[2] = v2;

    // Linking the edges to the face
    
    e0 -> adjface[0] = e1 -> adjface[0] = e2 -> adjface[0] = f;

    return f;

}