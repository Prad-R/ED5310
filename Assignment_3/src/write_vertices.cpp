#include "incremental.hpp"

void Write_Vertices() {

    // std::cout << "In Write_Vertices()\n";

    Vertex v = vertices;

    // Locate_Vertex_Head();

    do {

        std::cout << "Point " << v -> vnum << " : " << v -> v[X] << " " << v -> v[Y] << " " << v -> v[Z] << "\n";
        v = v -> next;

    } while (v != vertices);

}

void Write_Edges() {

    // std::cout << "In Write_Edges()\n";

    Edge e = edges;

    // Locate_Edge_Head();

    do {

        std::cout << "Edge with vertices : " << e -> endpts[0] -> vnum << " " << e -> endpts[1] -> vnum << "\n";
        e = e -> next;

    } while (e != edges);

}

void Write_Faces() {

    // std::cout << "In Write_Faces()\n";

    Face f = faces;

    // Locate_Face_Head();

    int i = 0;

    do {
        
        std::cout << "Face with vertices : " << f -> vertex[0] -> vnum << " " << f -> vertex[1] -> vnum << " " << f -> vertex[2] -> vnum << "\n";
        // std::cout << "Visible status : " << f -> visible << "\n";
        f = f -> next;

    } while (f !=  faces);

}

void Inspect_Vertex(Vertex v) {

    // std::cout << "In Inspect_Vertex()\n";

    std::cout << "Inspecting point " << v -> vnum << " with coordinates : " << v -> v[X] << " " << v -> v[Y] << " " << v -> v[Z] << "\n";
    // std::cout << "Processed status : " << v -> mark << "\n";
    // std::cout << "Onhull status : " << v -> onhull << "\n";

}

void Inspect_Edge(Edge e) {

    // std::cout << "In Inspect_Edge()\n";

    std::cout << "The edge has the vertices  : " << e -> endpts[0] -> vnum << " " << e -> endpts[1] -> vnum << "\n";

}

void Inspect_Face(Face f) {

    // std::cout << "In Inspect_Face()\n";

    std::cout << "The face has the vertices : " << f -> vertex[0] -> vnum << " " << f -> vertex[1] -> vnum << " " << f -> vertex[2] -> vnum << "\n";

}

void Processed_Status() {

    // std::cout << "In Processed_Status()\n";

    Vertex v = vertices;

    do {

        std::cout << "Processed status of point " << v -> vnum << " : " << v -> mark << "\n";
        v = v -> next;

    } while (v != vertices);

}

void Locate_Vertex_Head() {

    // std::cout << "In Locate_Vertex_Head()\n";

    std::cout << "The vertex head is at point " << vertices -> vnum << "\n";

}

void Locate_Edge_Head() {

    // std::cout << "In Locate_Edge_Head()\n";

    std::cout << "The edge head is at edge with vertices : " << edges -> endpts[0] -> vnum << " " << edges -> endpts[1] -> vnum << "\n";

}

void Locate_Face_Head() {

    // std::cout << "In Locate_Face_Head()\n";

    std::cout << "The face head is at the face with vertices : " << faces -> vertex[0] -> vnum << " " << faces -> vertex[1] -> vnum << " " << faces -> vertex[2] -> vnum << "\n";

}