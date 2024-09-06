#include "triangulation.hpp"

// Diagonalie() checks if the diagonal intersects any of the edges

bool Diagonalie(Vertex a, Vertex b) {

    // std::cout << "In Diagonalie()\n";

    Vertex c, c1;

    c = vertices;

    do {

        c1 = c -> next;

        // Skipping edges incident to a or b        

       if ((c != a) && (c1 != a) && (c != b) && (c1 != b) && Intersect(a -> v, b -> v, c -> v, c1 -> v)) {

            // std::cout << "FALSE\n";
            return false;

       }

       c = c -> next; 

    } while(c != vertices);

    // std::cout << "TRUE\n";
    return true;

}

bool Diagonal(Vertex a, Vertex b){

    // std::cout << "In Diagonal()\n";

    return In_Cone(a, b) && In_Cone(b, a) && Diagonalie(a, b);

}