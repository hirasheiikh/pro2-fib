#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t){
    if (t.empty()) return t;
    else{
        BinTree<int> ti = reverseTree(t.left());
        BinTree<int> td = reverseTree(t.right());
        return BinTree<int>(t.value(), td, ti);
    }
}