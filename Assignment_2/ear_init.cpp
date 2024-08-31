#include "triangulation.hpp"

void EarInit() {

    tVertex v0, v1, v2;

    v1 = vertices;

    do {

        v2 = v1 -> next;
        v0 = v1 -> prev;
        v1 -> ear = Diagonal(v0, v1);
        v1 = v1 -> next;

    } while(v1 != vertices);

}