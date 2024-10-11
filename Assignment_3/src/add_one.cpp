#include "incremental.hpp"

bool Add_One(Vertex p) {

    // std::cout << "In Add_One()\n";

    Face f;
    Edge e, temp;
    bool vis = false;

    // Marking faces visible from p

    // Locate_Face_Head();
    f = faces;
    do {

        if (Volume_Sign(f, p) <  0 ) {

            f -> visible = VISIBLE;
            vis = true;

        }

        f = f -> next;

    } while (f != faces);

    // Write_Faces();

    // If no faces are visible from p, p is inside the hull

    if (!vis) {

        p -> onhull = !ONHULL;
        return false;

    }

    // Marking edges in interior of visible region for deletion

    // Locate_Edge_Head();
    e = edges;
    do {

        temp = e -> next;

        if (e -> adjface[0] -> visible && e -> adjface[1] -> visible) // e is in the interior of the visible region
            e -> to_delete = REMOVED;
        else if (e -> adjface[0] -> visible || e -> adjface[1] -> visible) // e is in the border of the visible region
            e -> newface = Make_Cone_Face(e, p);
        
        e = temp;

    } while (e != edges);

    return true;

}