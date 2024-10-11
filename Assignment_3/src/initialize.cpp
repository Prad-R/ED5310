#include "incremental.hpp"

Vertex vertices = NULL;
Edge edges = NULL;
Face faces = NULL;

Vertex Make_Null_Vertex() {

    // std::cout << "In Make_Null_Vertex()\n";

    Vertex v;

    NEW(v, sVertex);

    v -> duplicate = NULL;
    v -> onhull = !ONHULL;
    v -> mark = !PROCESSED;

    ADD(vertices, v);

    return v;

}

Edge Make_Null_Edge() {

    // std::cout << "In Make_Null_Edge()\n";

    Edge e;

    NEW(e, sEdge);

    e -> adjface[0] = e -> adjface[1] = e -> newface = NULL;
    e -> endpts[0] = e -> endpts[1] = NULL;
    e -> to_delete = !REMOVED;
    
    ADD(edges, e);

    return e;

}

Face Make_Null_Face() {

    // std::cout << "In Make_Null_Face()\n";

    Face f;

    NEW(f, sFace);

    for (int i = 0; i < 3; ++ i) {

        f -> edge[i] = NULL;
        f -> vertex[i] = NULL;

    }

    f -> visible = !VISIBLE;

    ADD(faces, f);

    return f;

}