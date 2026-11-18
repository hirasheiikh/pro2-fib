#include "treeOfSumsOfAncestors.hh"


BinTree<int> i_treeOfSumsOfAncestors(BinTree<int>t, int n) {
    //cas base, si l'arbre està buit
    if (t.empty()) return BinTree<int>(); 
    //cas recursiu, retornem l'arbre amb l'arrel actualitzada i cridant recursivament a l'arbre esquerre i al dret amb la nova n
    else return BinTree<int>(t.value() + n, i_treeOfSumsOfAncestors(t.left(), n+t.value()), i_treeOfSumsOfAncestors(t.right(), n+t.value())); 
}

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
   return i_treeOfSumsOfAncestors(t, 0); // cridem a funció immersiva
}