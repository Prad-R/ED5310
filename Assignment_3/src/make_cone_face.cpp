#include "incremental.hpp"

Face Make_Cone_Face(Edge e, Vertex p) {

    // std::cout << "----- In Make_Cone_Face()\n";

    // Inspect_Edge(e);
    // Inspect_Vertex(p);

    Edge new_edge[2];
    Face new_face;

    // Loop for making two new edges if they don't already exist

    for (int i = 0; i < 2; ++ i){

        // If edge exists, copy into new_edge
        if (!(new_edge[i] = e -> endpts[i] -> duplicate)) {

            // If not exists (NULL), make a null edge and initialize

            new_edge[i] = Make_Null_Edge();
            new_edge[i] -> endpts[0] = e -> endpts[i];
            new_edge[i] -> endpts[1] = p;
            
            e -> endpts[i] -> duplicate = new_edge[i];

            // std::cout << "Created new edge on hull\n";
            // Inspect_Edge(new_edge[i]);

        }

    }

    // Inspect_Edge(new_edge[0]);
    // Inspect_Edge(new_edge[1]);

    // Make the new cone face

    new_face = Make_Null_Face();
    new_face -> edge[0] = e;
    new_face -> edge[1] = new_edge[0];
    new_face -> edge[2] = new_edge[1];

    // Arrange the edges to make the face traversal CCW

    Make_CCW(new_face, e, p);

    // Inspect_Face(new_face); 

    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j) {

            // For a newly added edge, both of the adjacent faces will be NULL
            // The break statement ensures that for each edge, we set only one of the NULL links to the face

            if (!new_edge[i] -> adjface[j]) {

                new_edge[i] -> adjface[j] = new_face;
                break;

            }

        }

    // std::cout << "Created new face on hull\n";
    // Inspect_Face(new_face);

    // Write_Faces();

    return new_face;

}