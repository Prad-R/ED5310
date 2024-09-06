#ifndef TRIANGULATION_HPP
#define TRIANGULATION_HPP

#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<chrono>

#define X 0
#define Y 1

#define DIM 2
typedef int Point[DIM];

typedef struct VertexStruct sVertex;

typedef sVertex* Vertex;

struct VertexStruct {

    int vnum; /* Index */
    Point v; /* Coordinates */
    bool ear; /* TRUE if an ear */
    Vertex next, prev;

    VertexStruct() {
        vnum = 0;
        v[0] = 0;
        v[1] = 0;
        ear = false;
        next = NULL;
        prev = NULL;
    }

};

extern Vertex vertices; /* "Head" of circular list */
extern int n_vertices; /* Number of vertices of the polygon */

// --------------------------------------
// Function declarations
// --------------------------------------


int Area_2(Point a, Point b, Point c);

int Area_Poly_2();

bool Left(Point a, Point b, Point c);

bool Left_On(Point a, Point b, Point c);

bool Collinear(Point a, Point b, Point c);

bool Intersect_Prop(Point a, Point b, Point c, Point d);

bool Between(Point a, Point b, Point c);

bool Intersect(Point a, Point b, Point c, Point d);

bool Diagonalie(Vertex a, Vertex b);

bool In_Cone(Vertex a, Vertex b);

bool Diagonal(Vertex a, Vertex b);

void Ear_Init();

void Triangulate_n2(int n_vertices, std::string filename);

void Triangulate_n4(int n_vertices, std::string filename);

void Print_Diagonal(Vertex a, Vertex b);

void Write_Diagonal(Vertex a, Vertex b, std::string filename);

int Find_Lines(std::string filename);

void Link_Vertices(Vertex* &polygon, int n_vertices);

void Read_Vertices(Vertex* &polygon, std::string filename);

void Print_Vertices(Vertex* &polygon, int n_vertices);

void Initialize_Polygon(Vertex* &polygon, int n_vertices);

void Clean_Up_Polygon(Vertex* &polygon, int n_vertices);

#endif