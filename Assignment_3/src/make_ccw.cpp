#include "incremental.hpp"

void Make_CCW(Face f, Edge e, Vertex p) {

    // std::cout << "In Make_CCW()\n";

    Face fv; // Visible Face adjacent to e
    Edge s; // Temporary Edge for Swapping

    if (e -> adjface[0] -> visible)
        fv = e -> adjface[0];
    else
        fv = e -> adjface[1];

    // Inspect_Face(fv);
    // Inspect_Edge(e);

    // Ensures that the new face f has the same orientation as the face sharing the same edge but visible to the new point
    int i;

    for (i = 0; fv -> vertex[i] != e -> endpts[0]; ++ i);

    // for (int i = 0; i < 2; ++ i) {

    if (fv -> vertex[(i + 1) % 3] != e -> endpts[1]) {

        f -> vertex[0] = e -> endpts[1];
        f -> vertex[1] = e -> endpts[0];
        // std::cout << "NO SWAP!\n";

    }
    else {

        f -> vertex[0] = e -> endpts[0];
        f -> vertex[1] = e -> endpts[1];
        // std::cout << "SWAP!\n";
        SWAP(s, f -> edge[1], f -> edge[2]);

    }

    f -> vertex[2] = p;

    // Inspect_Face(f);

}