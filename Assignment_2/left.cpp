#include "triangulation.hpp"

bool Left(tPointi a, tPointi b, tPointi c) {

    return Area2(a, b, c) > 0;

}

bool LeftOn(tPointi a, tPointi b, tPointi c) {

    return Area2(a, b, c) >= 0;

}

bool Collinear(tPointi a, tPointi b, tPointi c) {

    return Area2(a, b, c) == 0;

}