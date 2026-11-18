#include "numberOfLeaves.hh"


int aux (BinTree<int> t, int suma){
    if (t.empty()) suma = 0;
    else{
        if (t.right().empty() and t.left().empty()) ++suma;
        if (not t.right().empty()) suma += numberOfLeaves(t.right());
        if (not t.left().empty()) suma += numberOfLeaves(t.left());
    }
    return suma;

}

// Pre:
// Post: Retorna el nombre de fulles de t
int numberOfLeaves(BinTree<int> t){
    return aux (t, 0);

    
}