#include "triangulation.hpp"

bool Intersect_Prop(Point a, Point b, Point c, Point d) {

    if (Collinear(a, b, c) || Collinear(a, b, d) || Collinear(c, d, a) || Collinear(c, d, b)) {

        return false;

    }

    return (Left(a, b, c) ^ Left(a, b, d)) && (Left(c, d, a) ^ Left (c, d, b));

}

// For improper intersections, that is the second line segment originates from somewhere on the first

bool Between(Point a, Point b, Point c) {

    Point ba, ca;

    if (!Collinear(a, b, c))
        return false;

    // If ab not vertical, check betweenness on x, else y.
    
   if (a[X] != b[X])
        return ((a[X] <= c[X]) && (c[X] <= b[X])) || ((b[X] <= c[X]) && (c[X] <= a[X]));
   else
        return ((a[Y] <= c[Y]) && (c[Y] <= b[Y])) || ((b[Y] <= c[Y]) && (c[Y] <= a[Y]));

}

bool Intersect(Point a, Point b, Point c, Point d) {

    if (Intersect_Prop(a, b, c, d))
        return true;
    else if (Between(a, b, c) || Between(a, b, d) || Between (c, d, a) || Between(c, d, b))
        return true;
    else
        return false;

}