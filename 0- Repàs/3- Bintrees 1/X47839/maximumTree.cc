#include "maximumTree.hh"


BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2){
    if (a1.empty() and a2.empty()) return BinTree<int> ();
    else if (a1.empty()) return a2;
    else if (a2.empty()) return a1;
    else{
        int x;
        if (a1.value() >= a2.value()) x = a1.value();
        else x = a2.value();
        BinTree<int> re = maximumTree (a1.left(), a2.left());
        BinTree<int> rd = maximumTree (a1.right(), a2.right());
        return BinTree<int> (x, re, rd);
    }

}