#include "incremental.hpp"

void Clean_Up() {

    Clean_Edges();
    Clean_Faces();
    Clean_Vertices();

}

void Clean_Faces() {

    Face f;
    Face temp; // Temporary pointer for deleting

    while (faces && faces -> visible) {

        f = faces;
        DELETE(faces, f);

    }

    f = faces -> next;

    do {

        if (f -> visible) {

            temp = f;
            f = f -> next;
            DELETE(faces, temp);

        }
        else
            f = f -> next;

    } while (f != faces);

}

void Clean_Edges() {

    Edge e; // Primary index into edge list
    Edge temp; // Temporary edge pointer

    // Integrate the newly formed faces into the data structure
    
    e = edges;
    do {

        // Check if the edge has a new face formed

        if (e -> newface) {

            // If there is a new face, replace the previously visible edge with the new face

            if (e -> adjface[0] -> visible)
                e -> adjface[0] = e -> newface;
            else
                e -> adjface[1] = e -> newface;

            // Set the new face back to NULL for the next increment

            e -> newface = NULL;

        }

        e = e -> next;

    } while (e != edges);

    while (edges && edges -> to_delete) {

        e = edges;
        DELETE(edges, e);

    }

    e = edges -> next;

    do {

        if (e -> to_delete) {

            temp = e;
            e = e -> next;
            DELETE(edges, temp);

        }
        else
            e = e -> next;

    } while (e != edges);

}

void Clean_Vertices() {

    Edge e;
    Vertex v, temp;

    // Marking all vertices incident to some undeleted edge as ONHULL

    e = edges;
    do {

        e -> endpts[0] -> onhull = e -> endpts[1] -> onhull = ONHULL;
        e = e -> next;

    } while (e != edges);

    // Deleting all vertices that have been processed but are not on the hull

    while(vertices && vertices -> mark && !vertices -> onhull) {

        v = vertices;
        DELETE(vertices, v);

    }

    v = vertices -> next;

    do {

        if (v -> mark && !v -> onhull) {

            temp = v;
            v = v -> next;
            DELETE(vertices, temp);

        }
        else
            v = v -> next;

    } while (v != vertices);

    // Resetting flags
    
    v = vertices;

    do {

        v -> duplicate = NULL;
        v -> onhull = !ONHULL;
        v = v -> next;

    } while (v !=  vertices);

}