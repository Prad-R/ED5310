#include "incremental.hpp"

void Make_CCW(Face f, Edge e, Vertex p) {

    Face fv; // Visible Face adjacent to e
    Edge s; // Temporary Edge for Swapping

    if (e -> adjface[0] -> visible)
        fv = e -> adjface[0];
    else
        fv = e -> adjface[1];

    // Ensures that the new face f has the same orientation as the face sharing the same edge but visible to the new point
    
    for (int i = 0; fv -> vertex[i] != e -> endpts[0]; i ++) {

        if (fv -> vertex[(i + 1) % 3] != e -> endpts[1]) {

            f -> vertex[0] = e -> endpts[1];
            f -> vertex[1] = e -> endpts[0];

        }
        else {

            f -> vertex[0] = e -> endpts[0];
            f -> vertex[1] = e -> endpts[1];
            SWAP(s, f -> edge[1], f -> edge[2]);

        }

    }

    f -> vertex[2] = p;

}