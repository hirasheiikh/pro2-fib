#include "sumAtDepthEven.hh"


int sum_parells(BinTree<int> t, int nivell){
    int suma = 0;
    if (not t.left().empty()) suma += sum_parells(t.left(), nivell + 1);
    if (not t.right().empty()) suma += sum_parells(t.right(), nivell + 1);
    if (nivell%2 == 0) suma += t.value();
    return suma;
}


int sumAtDepthEven(BinTree<int> t){
    if (not t.empty()) return sum_parells(t,0);
    else return 0;
    
}
