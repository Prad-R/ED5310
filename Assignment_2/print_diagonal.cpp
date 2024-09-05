#include "triangulation.hpp"

void PrintDiagonal(tVertex a, tVertex b) {

    std::cout << "\n(" << a -> vnum << "," << b -> vnum << ") is a triangulating diagonal\n"; 

}

void WriteDiagonal(tVertex a, tVertex b, std::string filename) {

    std::ofstream file(filename.c_str(), std::ios::out|std::ios::app);

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    } 
    
    file << "Diag: " << a -> vnum <<  " " << b -> vnum << std::endl;

    file.close();

}