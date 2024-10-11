#include "incremental.hpp"

int main(int argc, char* argv[]) {

    int n_points = std::atoi(argv[1]);

    // std::cout << "In main()\n";

    Create_Points(n_points);
    // Read_Vertices();
    // Read_Vertices_Cube();

    std::cout << "\n------------ Input Points -------------\n\n";
    Write_Vertices();

    Double_Triangle();
    Construct_Hull();

    // Processed_Status();
    
    // std::cout << "\n-------------- Final Points on Hull ----------------\n\n";
    // Write_Vertices();

    // std::cout << "\n-------------- Final Edges on Hull ----------------\n\n";
    // Write_Edges();

    // std::cout << "\n-------------- Final Faces Given Below ----------------\n\n";
    // Write_Faces();

    std::cout << "\n-------------- Writing to STL ----------------\n\n";
    Write_STL();

    std::cout << "\n-------------- Done -------------------\n\n";

    return 0;

}