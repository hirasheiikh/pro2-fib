#include "longestLeftmostPath.hh"


list<int> longestLeftmostPath(BinTree<int> t){
    if (t.empty()) return list<int>();
    list<int> leftPath = longestLeftmostPath(t.left());
    list<int> rightPath = longestLeftmostPath(t.right());
    if (leftPath.size() < rightPath.size()){
        rightPath.push_front(t.value());
        return rightPath;
    }
    else {
        leftPath.push_front(t.value());
        return leftPath;
    }
    
}