#include "triangulation.hpp"

bool Left(Point a, Point b, Point c) {

    return Area_2(a, b, c) > 0;

}

bool Left_On(Point a, Point b, Point c) {

    return Area_2(a, b, c) >= 0;

}

bool Collinear(Point a, Point b, Point c) {

    return Area_2(a, b, c) == 0;

}