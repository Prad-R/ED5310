#include "triangulation.hpp"

Vertex vertices = NULL;

// Function to find the number of lines in the file

int Find_Lines(std::string filename) {

    // std::cout << "In FindLines()\n";

    std::ifstream file(filename.c_str());

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return 0;
    }

    std::string line;
    int n_lines = 0;

    while(std::getline(file, line))
        n_lines += 1;

    return n_lines;

}

// Funtion to link the vertices to form a doubly-linked circular list to represent the poylgon

void Link_Vertices(Vertex* &polygon, int n_vertices) {

    // std::cout << "In LinkVertices()\n";

    for (int i = 1; i < n_vertices - 1; i ++) {

        polygon[i] -> next = polygon[i + 1];
        polygon[i] -> prev = polygon[i - 1];

    }

    polygon[0] -> next = polygon[1];
    polygon[0] -> prev = polygon[n_vertices - 1];
    
    polygon[n_vertices - 1] -> next = polygon[0];
    polygon[n_vertices - 1] -> prev = polygon[n_vertices - 2];

}

void Read_Vertices(Vertex* &polygon, std::string filename){

    // std::cout << "In ReadVertices()\n";

    std::ifstream file(filename.c_str());

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    }

    std::string line;
    int v_no = 0;
    int x, y;

    while(file >> x >> y) {

        polygon[v_no] -> v[X] = x;
        polygon[v_no] -> v[Y] = y;

        v_no += 1;

    }

    file.close();

    Link_Vertices(polygon, v_no);

}