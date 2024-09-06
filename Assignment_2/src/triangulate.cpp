#include "triangulation.hpp"

void Triangulate_n2(int n_vertices, std::string filename){

    // std::cout << "In Triangulate_n2()\n";

    Vertex v0, v1, v2, v3, v4;
    int n = n_vertices;

    Ear_Init();   

    while(n > 3) {

        v2 = vertices;

        do {

            
            // If ear is found, fill the variables
            
            if (v2 -> ear) {

               v3 = v2 -> next;
               v4 = v3 -> next;
               v1 = v2 -> prev;
               v0 = v1 -> prev;

               // PrintDiagonal(v1, v3);
               Write_Diagonal(v1, v3, filename);

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

    // std::cout << "\n..... Triangulation Complete! .....\n";

}

void Triangulate_n4(int n_vertices, std::string filename){

    // std::cout << "In Triangulate_n4()\n";

    Vertex v0, v1, v2, v3, v4;
    int n = n_vertices;

    Ear_Init();   

    while(n > 3) {

        v2 = vertices;

        do {

            
            // If ear is found, fill the variables
            
            if (v2 -> ear) {

               v3 = v2 -> next;
               v4 = v3 -> next;
               v1 = v2 -> prev;
               v0 = v1 -> prev;

               // PrintDiagonal(v1, v3);
               Write_Diagonal(v1, v3, filename);

               // Removing the ear v2 from the polygon
               
               v1 -> next = v3;
               v3 -> prev = v1;
               vertices = v3;
               n --;

               // Initializing the ears of the polygon again since it has been modified

               Ear_Init(); 

               break;

            }

            v2 = v2 -> next;

        } while(v2 != vertices);

    }

    // std::cout << "\n..... Triangulation Complete! .....\n";

}