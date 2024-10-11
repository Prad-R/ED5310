#include "incremental.hpp"

void Construct_Hull() {

    // std::cout << "In Construct_Hull()\n";

    Vertex v, vnext;
    int vol;

    // Locate_Vertex_Head();
    v = vertices;

    do {

        vnext = v -> next;

        if (!v -> mark) {

            v -> mark = PROCESSED;
            bool inside = Add_One(v);
            // std::cout << "Point " << v -> vnum << " inside hull status : " << !inside << "\n";
            // Processed_Status();
            Clean_Up();

        }

        // std::cout << "------------------------- The hull is formed for this step! ---------------------------\n";
        // Write_Edges();
        // Write_Faces();

        v = vnext;

    } while (v != vertices);

}