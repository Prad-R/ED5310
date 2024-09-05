#include "triangulation.hpp"


// Function for initializing the array of structures at run time

void InitializePolygon(tVertex* &polygon, int n_vertices) {

    // std::cout << "In InitializePolygon()\n";

    for (int i = 0; i < n_vertices; i ++) {

        polygon[i] = new tsVertex();
        polygon[i] -> vnum = i;

    }

}


// Function for deleting the dynamically allocated memory

void CleanUpPolygon(tVertex* &polygon, int n_vertices) {

    // std::cout << "In CleanUpPolygon()\n";

    for (int i = 0; i < n_vertices; i ++) {

        delete polygon[i];

        // To erase nullify the dangling pointer created due to the pointer pointing to the deleted memory adress

        polygon[i] = NULL;

    }

}

int main() {

    std::string filename;

    std::stringstream ss;

    int test_cases = 15;

    for (int i = 0; i < test_cases; i ++) {

        ss.str("");
        ss.clear();

        ss << "./Polygon_Generator/Test_Cases/Test_Case_" << i + 1 << ".csv";

        filename = ss.str();

        // std::cout << i << " " << filename << std::endl;

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

        polygon = NULL;

        // std::cout << "Deleted poylgon\n";

    }

    return 0;

}