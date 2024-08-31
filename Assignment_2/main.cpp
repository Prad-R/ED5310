#include "triangulation.hpp"

int main() {

    int n_vertices;

    std::cout << "Enter the number of vertices of the polygon :\n";
    std::cin >> n_vertices;

    ReadVertices(n_vertices);
    PrintVertices(n_vertices);
    Triangulate(n_vertices);

    return 0;
}