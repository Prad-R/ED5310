#ifndef INCREMENTAL_HPP
#define INCREMENTAL_HPP

#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#define X 0
#define Y 1
#define Z 2

#define DIM 3

#define ONHULL true
#define REMOVED true
#define VISIBLE true
#define PROCESSED true

typedef struct VertexStruct sVertex;
typedef sVertex* Vertex;

typedef struct EdgeStruct sEdge;
typedef sEdge* Edge;

typedef struct FaceStruct sFace;
typedef sFace* Face;

struct VertexStruct {

    int v[DIM]; // Coordinates of the point
    int vnum; // Index of the vertex

    Edge duplicate; // Pointer to incident cone edge
    bool onhull; // True iff point on the hull
    bool mark; // True iff point is already processed

    Vertex next, prev;

};

struct EdgeStruct {

    Face adjface[2]; // Pointer to faces that share this edge
    Vertex endpts[2]; // Pointer to the endpoints of this edge

    Face newface; // Pointer to incident cone face
    bool to_delete; // True iff edge should be deleted.

    Edge next, prev;

};

struct FaceStruct {

    Edge edge[3]; // Pointer to the three edges of the triangular face
    Vertex vertex[3]; // Pointer to the three vertices of the triangular face

    bool visible; // True iff face is visible from new point

    Face next, prev;

};

extern Vertex vertices; // Head of circular list of vertices
extern Edge edges; // Head of circular list of edges
extern Face faces; // Head of circular list of faces
extern int n_vertices; // Number of points in the input

// ------------------------
// Defining Macros
// ------------------------

#define EXIT_FAILURE 1

#define NEW(p, type) \
    if ((p = (type*) malloc (sizeof(type))) == NULL) { \
    \
        std::cout << "NEW : Out of Memory!\n"; \
        exit(EXIT_FAILURE); \
    \
    }

#define ADD(head, p) \
    if (head) { \
    \
        p -> next = head; \
        p -> prev = head -> prev; \
        head -> prev = p; \
        p -> prev -> next = p; \
    \
    } \
    else {\
    \
        head = p; \
        head -> next = head -> prev = p; \
    \
    }

#define FREE(p) \
    if (p) { \
    \
        free (p); \
        p = NULL; \
    \
    }

#define DELETE(head, p) \
    if (head) { \
        \
        if (head == head -> next) \
            head = NULL; \
        else if (p == head) \
            head = head -> next; \
        \
        p -> next -> prev = p -> prev; \
        p -> prev -> next =  p -> next; \
        \
        FREE(p); \
        \
    }

#define SWAP(t, x, y) \
    t = x; \
    x = y; \
    y = t; \

// ------------------------
// Function Declarations
// ------------------------

Vertex Make_Null_Vertex();

Edge Make_Null_Edge();

Face Make_Null_Face();

int Volum_Sign(Face f, Vertex p);

Face Make_Cone_Face(Edge e, Vertex p);

void Make_CCW(Face f, Edge e, Vertex p);

void Clean_Up();

void Clean_Edges();

void Clean_Faces();

void Clean_Vertices();

#endif