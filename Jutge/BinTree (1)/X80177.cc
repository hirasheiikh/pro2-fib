#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t){
    if (t.empty()) return t;
    else{
        BinTree<int> rd = reverseTree(t.right());
        BinTree<int> re = reverseTree(t.left()); 
        return BinTree<int>(t.value(), rd, re);
    }
}