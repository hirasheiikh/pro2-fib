#include"BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a){
    ParInt p;
    if (p.llegir()){
        BinTree<ParInt> a_left, a_right;
        read_bintree_parint(a_left);
        read_bintree_parint(a_right);
        a = BinTree<ParInt>(p, a_left, a_right);
    }
}

void write_bintree_parint(const BinTree<ParInt>& a); // (opcional)
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A