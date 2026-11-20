#include <iostream>

using namespace std;

#include "BinTree.hh"


//Pre: p es la profunditat de l'arbre t
//Post: Retorna la suma dels valors de t a profunditat parell
int i_sumADepthEven(BinTree<int>t, int p){
    if (t.empty()) return 0;
    else {
        int suma = 0;
        if (p%2 == 0) suma += t.value();
        int se = i_sumADepthEven(t.left(), p + 1);
        int sd = i_sumADepthEven(t.right(), p + 1);
        suma += se + sd;
        return suma;
    }
}

//Pre: 
//Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinTree<int> t){
    int p = 0;
    return i_sumADepthEven(t, p);
}
