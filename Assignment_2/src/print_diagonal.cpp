#include "triangulation.hpp"

void Print_Diagonal(Vertex a, Vertex b) {

    std::cout << "\n(" << a -> vnum << "," << b -> vnum << ") is a triangulating diagonal\n"; 

}

void Write_Diagonal(Vertex a, Vertex b, std::string filename) {

    std::ofstream file(filename.c_str(), std::ios::out|std::ios::app);

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    } 
    
    file << "Diag: " << a -> vnum <<  " " << b -> vnum << std::endl;

    file.close();

}