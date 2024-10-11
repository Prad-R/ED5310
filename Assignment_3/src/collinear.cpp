#include "incremental.hpp"

bool Collinear(Vertex a, Vertex b, Vertex c) {

   // std::cout << "In Collinear()\n";

    return    (c -> v[Z] - a -> v[Z]) * (b -> v[Y] - a -> v[Y]) -
              (b -> v[Z] - a -> v[Z]) * (c -> v[Y] - a -> v[Y]) == 0
           && (b -> v[Z] - a -> v[Z]) * (c -> v[X] - a -> v[X]) -
              (b -> v[X] - a -> v[X]) * (c -> v[Z] - a -> v[Z]) == 0
           && (b -> v[X] - a -> v[X]) * (c -> v[Y] - a -> v[Y]) -
              (b -> v[Y] - a -> v[Y]) * (c -> v[X] - a -> v[X]) == 0;     

}