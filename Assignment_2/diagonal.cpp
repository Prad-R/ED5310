#include "triangulation.hpp"

bool Diagonalie(tVertex a, tVertex b) {

    // std::cout << "In Diagonalie()\n";

    tVertex c, c1;

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

bool Diagonal(tVertex a, tVertex b){

    // std::cout << "In Diagonal()\n";

    return InCone(a, b) && InCone(b, a) && Diagonalie(a, b);

}