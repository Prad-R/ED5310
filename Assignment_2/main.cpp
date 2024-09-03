#include "triangulation.hpp"


// Function for initializing the array of structures at run time

void InitializePolygon(tVertex* &polygon, int n_vertices) {

    for (int i = 0; i < n_vertices; i ++) {

        polygon[i] = new tsVertex();
        polygon[i] -> vnum = i;

    }

}


// Function for deleting the dynamically allocated memory

void CleanUpPolygon(tVertex* &polygon, int n_vertices) {

    for (int i = 0; i < n_vertices; i ++) {

        delete polygon[i];

    }

}

int main() {

    const char* filename = "./Polygon_Generator/Test_Cases/Test_Case_1.csv";

    int n_vertices = FindLines(filename);

    // Dynamically allocating memory to an array of vertices and returning a pointer to the beginning of the array

    tVertex* polygon = new tVertex[n_vertices];

    InitializePolygon(polygon, n_vertices);

    // Read the vertices of the polygon from a test case file

    ReadVertices(polygon, filename);

    // Initialize the head to the first vertex

    vertices = polygon[0];

    // PrintVertices(polygon, n_vertices);

    Triangulate(n_vertices, filename);

    CleanUpPolygon(polygon, n_vertices);

    // Deleting the dynamically allocated memory

    delete[] polygon;

    return 0;

}