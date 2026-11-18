#include "longestLeftmostPath.hh"


list<int> longestLeftmostPath(BinTree<int> t){
  if (t.empty()) return llist<int>();
  list<int> leftpath = longestLeftmostPath(t.left());
  list<int> rightpath = longestLeftmostPath(t.right());
  if (leftpath.size() < rightpath.size()){
    rightpath.push_front(t.value()); // important crear la llista
    return rightpath;
  }
  else{
    leftpath.push_front(t.valu());
    return leftpath;
  }
}