#include "triangulation.hpp"

void Triangulate(int n_vertices){

    // std::cout << "In Triangulate()\n";

    tVertex v0, v1, v2, v3, v4;
    int n = n_vertices;

    EarInit();

    while(n > 3) {

        v2 = vertices;

        do {

            
            // If ear is found, fill the variables
            
            if (v2 -> ear) {

               v3 = v2 -> next;
               v4 = v3 -> next;
               v1 = v2 -> prev;
               v0 = v1 -> prev;

               PrintDiagonal(v1, v3);

               // Update the ear status of vertices adjacent to the ear
            
               v1 -> ear = Diagonal(v0, v3);
               v3 -> ear = Diagonal(v1, v4);

               // Removing the ear v2 from the polygon
               
               v1 -> next = v3;
               v3 -> prev = v1;
               vertices = v3;
               n --;
               break;

            }

            v2 = v2 -> next;

        } while(v2 != vertices);

    }

    std::cout << "\n..... Triangulation Complete! .....\n";

}