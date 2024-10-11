#include "incremental.hpp"

void Create_Points(int n_points) {

    // Create a random number generator with a seed

    std::random_device rd; // Seed generator
    std::mt19937 mt(rd()); // Mersenne Twister PRNG with the seed

    // Uniform distribution of integers between 0 and 500

    std::uniform_int_distribution<int> distrib(0, 500);

    Vertex v;

    for (int i = 0; i < n_points; i ++) {

        v = Make_Null_Vertex();

        v -> v[X] = distrib(mt);
        v -> v[Y] = distrib(mt);
        v -> v[Z] = distrib(mt); 

        v -> vnum = i;

    }

}

void Read_Vertices() {

    std::cout << "In Read_Vertices()\n";

    Vertex v;
    int x, y, z;
    bool completed;
    int vnum = 0;

    while (!completed) {

        std::cout << "Enter vertex coordinates of point " << vnum << " : ";
        std::cin >> x >> y >> z;

        if (x == 404) {
            completed = true;
            std::cout << "Input Done!\n";
            break;
        }

        v = Make_Null_Vertex();

        v -> v[X] = x;
        v -> v[Y] = y;
        v -> v[Z] = z;

        v -> vnum = vnum ++;

    }

}

void Read_Vertices_Cube() {

    // std::cout << "In Read_Vertices_Cube()\n";

    Vertex v0 = Make_Null_Vertex();
    Vertex v1 = Make_Null_Vertex();
    Vertex v2 = Make_Null_Vertex();
    Vertex v3 = Make_Null_Vertex();
    Vertex v4 = Make_Null_Vertex();
    Vertex v5 = Make_Null_Vertex();
    Vertex v6 = Make_Null_Vertex();
    Vertex v7 = Make_Null_Vertex();
    
    v0 -> v[X] = 0;
    v0 -> v[Y] = 0;
    v0 -> v[Z] = 0;
    v0 -> vnum = 0;

    v1 -> v[X] = 0;
    v1 -> v[Y] = 10;
    v1 -> v[Z] = 0;
    v1 -> vnum = 1;

    v2 -> v[X] = 10;
    v2 -> v[Y] = 10;
    v2 -> v[Z] = 0;
    v2 -> vnum = 2;

    v3 -> v[X] = 10;
    v3 -> v[Y] = 0;
    v3 -> v[Z] = 0;
    v3 -> vnum = 3;

    v4 -> v[X] = 0;
    v4 -> v[Y] = 0;
    v4 -> v[Z] = 10;
    v4 -> vnum = 4;

    v5 -> v[X] = 0;
    v5 -> v[Y] = 10;
    v5 -> v[Z] = 10;
    v5 -> vnum = 5;

    v6 -> v[X] = 10;
    v6 -> v[Y] = 10;
    v6 -> v[Z] = 10;
    v6 -> vnum = 6;

    v7 -> v[X] = 10;
    v7 -> v[Y] = 0;
    v7 -> v[Z] = 10;
    v7 -> vnum = 7;

}