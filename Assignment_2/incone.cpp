#include "triangulation.hpp"

bool InCone(tVertex a, tVertex b) {

    // std::cout << "In InCone()\n";

    tVertex a0, a1;
    
    // a0, a, a1 are consecutive vertices
    
    a1 = a -> next;
    a0 = a -> prev;
    
    // Checking for 'a' being a convex vertex and then implementing incone
    
   if (LeftOn(a -> v, a1 -> v, a0 -> v)) {

        // std::cout << "Vertex " << a -> vnum << " is convex\n";
        return Left(a -> v, b -> v, a0 -> v) && Left(b -> v, a -> v, a1 -> v);

   }
   
   // If 'a' is a reflex vertex
   
   return !(LeftOn(a -> v, b -> v, a1 -> v) && LeftOn(b -> v, a -> v, a0 -> v)); 

}