#include "triangulation.hpp"

void PrintVertices(tVertex* &polygon, int n_vertices) {
    
    std::cout << "\n";

    for (int i = 0; i < n_vertices; i ++) {

        std::cout << "Vertex " << i << " is : (" << polygon[i] -> v[X] << "," << polygon[i] -> v[Y] << ")\n";

    }

}