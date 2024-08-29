#ifndef TRIANGULATION_HPP
#define TRIANGULATION_HPP

#include<stdlib.h>

#define X 0
#define Y 1

#define DIM 2
typedef int tPointi[DIM];


typedef struct tVertexStructure tsVertex;

typedef tsVertex* tVertex;

struct tVertexStructure {

    int vnum; /* Index */
    tPointi v; /* Coordinates */
    bool ear; /* TRUE if an ear */
    tVertex next, prev;

};

tVertex vertices = NULL; /* "Head" of circular list */

/*
    To dynamically allocate memory
*/
#define NEW(p, type) \
    if ((p = (type *) malloc(sizeof(type))) == NULL) { \
        printf ("NEW : Out of memory!\n"); \
        exit(EXIT_FAILURE); \    
    }

/*
    To add a new item to the doubly linked list just before the "head".
    First checks if "head" is NULL. If not it inserts, else it points p to itself in both directions
*/
#define ADD(head, p) if (head) { \
    p -> next = head; \
    p -> prev = head -> prev; \
    head -> prev = p; \
    p -> prev -> next = p; \
} \
    else {\
        head = p; \
        head -> next = head -> prev = p; \
    }

/*
    To free the allocated memory and set the pointer to NULL to avoid dangling pointers.
    The pointer is cast to char and the passed to free()
*/
#define FREE(p) if (p) {free ((char *) p); p = NULL;}

#endif