#include "triangulation.hpp"

// InternalDiagonal() is a O(n) check for whether a diagonal is internal to the polygon or not
// It is based on the logic that if the diagonal is internal, there are vertices on both sides of the diagonal
// However, this by itself is not sufficient as there could be vertices on both sides of the diagonal if the diagonal is intersecting
// If we use Diagonalie(), it eliminates the possibility of intersection, so together they give internal diagonals
// In other words, InternalDiagonal() returns false if and only if the diagonal is an exterior non-intersecting diagonal

bool InternalDiagonal(Vertex a, Vertex b) {

     Vertex c;

     bool on_left = false;

     bool on_right = false;

     c = vertices;

     do {

          if(Left(a -> v, b -> v, c -> v))
               on_left = true;
          else if (!Left_On(a -> v, b -> v, c -> v))
               on_right = true;

     } while(c != vertices);

     return on_left && on_right;

}


// InCone() is a constant time check for whether a diagonal is internal to the given polygon or not

bool In_Cone(Vertex a, Vertex b) {

    // std::cout << "In InCone()\n";

    Vertex a0, a1;
    
    // a0, a, a1 are consecutive vertices
    
    a1 = a -> next;
    a0 = a -> prev;
    
    // Checking for 'a' being a convex vertex and then implementing incone
    
   if (Left_On(a -> v, a1 -> v, a0 -> v)) {

        // std::cout << "Vertex " << a -> vnum << " is convex\n";
        return Left(a -> v, b -> v, a0 -> v) && Left(b -> v, a -> v, a1 -> v);

   }
   
   // If 'a' is a reflex vertex
   
   return !(Left_On(a -> v, b -> v, a1 -> v) && Left_On(b -> v, a -> v, a0 -> v)); 

}