#include "triangulation.hpp"

int Area_2(Point a, Point b, Point c) {

    return (((b[X] - a[X]) * (c[Y] - a[Y])) - ((c[X] - a[X]) * (b[Y] - a[Y])));

}

int Area_Poly2_() {

    int sum = 0;
    Vertex p, a;

    p = vertices;
    a = p -> next;

    do {

        sum += Area_2(p -> v, a ->v, a -> next -> v);
        a = a -> next;

    } while(a -> next != vertices);

    return sum;

}