#include "triangulation.hpp"

tVertex vertices = NULL;

void PrintDiagonal(tVertex a, tVertex b) {

    std::cout << "(" << a -> vnum << "," << b -> vnum << ") is a triangulating diagonal\n"; 

}