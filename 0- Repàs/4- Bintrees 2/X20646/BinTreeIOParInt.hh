#include "BinTree.hh"
#include "ParInt.hh"
using namespace std;

#include"BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a);

void write_bintree_parint(const BinTree<ParInt>& a); // (opcional)
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A