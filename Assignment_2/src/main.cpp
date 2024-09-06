#include "triangulation.hpp"


// Function for initializing the array of structures at run time

void Initialize_Polygon(Vertex* &polygon, int n_vertices) {

    // std::cout << "In InitializePolygon()\n";

    for (int i = 0; i < n_vertices; i ++) {

        polygon[i] = new sVertex();
        polygon[i] -> vnum = i;

    }

}


// Function for deleting the dynamically allocated memory

void Clean_Up_Polygon(Vertex* &polygon, int n_vertices) {

    // std::cout << "In CleanUpPolygon()\n";

    for (int i = 0; i < n_vertices; i ++) {

        delete polygon[i];

        // To erase nullify the dangling pointer created due to the pointer pointing to the deleted memory adress

        polygon[i] = NULL;

    }

}

int main(int argc, char* argv[]) {

    std::string filename;

    std::string run_time_file;

    std::stringstream ss;

    int test_cases = std::atoi(argv[2]);

    short complexity = std::atoi(argv[1]);

    ss << "./src/Testing_and_Visualisation/Run_Time_" << complexity << ".csv";

    run_time_file = ss.str();

    std::ofstream file(run_time_file.c_str(), std::ios::out|std::ios::app);

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return 0; 
    }

    for (int i = 0; i < test_cases - 3; i ++) {

        ss.str("");
        ss.clear();

        ss << "./src/Testing_and_Visualisation/New_Test_Cases/Test_Case_" << i + 4 << ".csv";

        filename = ss.str();

        // std::cout << i << " " << filename << std::endl;

        int n_vertices = Find_Lines(filename);

        // Dynamically allocating memory to an array of vertices and returning a pointer to the beginning of the array

        Vertex* polygon = new Vertex[n_vertices];

        Initialize_Polygon(polygon, n_vertices);

        // Read the vertices of the polygon from a test case file

        Read_Vertices(polygon, filename);

        // Initialize the head to the first vertex

        vertices = polygon[0];

        // PrintVertices(polygon, n_vertices);

        // clock_t start, end;

        auto t_start = std::chrono::high_resolution_clock::now();
        auto t_end = std::chrono::high_resolution_clock::now();

        if (complexity == 2) {
            
            t_start = std::chrono::high_resolution_clock::now();
            // start = clock();
            Triangulate_n2(n_vertices, filename);
            // end = clock();
            t_end = std::chrono::high_resolution_clock::now();

        }
        else if (complexity == 4) {
            
            t_start = std::chrono::high_resolution_clock::now();
            // start = clock();
            Triangulate_n4(n_vertices, filename);
            // end = clock();
            t_end = std::chrono::high_resolution_clock::now();

        }
        else {

            std::cout << "Only O(n^2) and O(n^4) complexities are currently available";
            return 0;

        }

        // float run_time = (double(end - start) / CLOCKS_PER_SEC) * 1000;

        std::chrono::duration <double, std::milli> ms_double = t_end - t_start;

        // std::cout << "The runtime was " << run_time << " ms\n";

        file << "Run: " << n_vertices << " " << ms_double.count() * 1000 << std::endl;

        Clean_Up_Polygon(polygon, n_vertices);

        // Deleting the dynamically allocated memory

        delete[] polygon;

        polygon = NULL;

        // std::cout << "Deleted poylgon\n";

        std::cout << "Triangulated " << i + 4 << std::endl;

    }

    file.close();

    return 0;

}