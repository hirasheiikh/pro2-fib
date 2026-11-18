#include "numLeftRight.hh"

BinTree<int> canvi (BinTree<int> t, int esq, int dreta){
    BinTree<int> a_right, a_left;
    if (not t.left().empty()) a_left = canvi(BinTree<int>, esq + 1, dreta);
    if (not t.right().empty()) a_right = canvi(BinTree<int>, esq, dreta + 1)
    if (t.value() == '-1') return BinTree<int>(esq, a_left, a_right);
    else return BinTree<int>(der, a_left, a_right);
}

BinTree<int> numLeftRight(BinTree<int> t){
    BinTree<int> canviat;
    if (not t.empty()) canviat = canvi(t,0,0);
    return canviat;

}