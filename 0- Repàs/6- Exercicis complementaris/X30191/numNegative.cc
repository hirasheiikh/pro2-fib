#include "utils.hh"
#include "numNegative.hh"

int aux(BinTree<string> t, int& count){
    if (t.empty()) return 0;
    else{
        if (t.value() == "-"){
            int res = aux(t.left(),count) - aux(t.right(),count);
            if (res < 0) ++count;
            return res;
        }
        else if (t.value() == "+"){
            int res = aux(t.left(),count) + aux(t.right(),count);
            if (res < 0) ++count; 
            return res;
        } 
        else if (t.value() == "*"){
            int res = aux(t.left(),count) * aux(t.right(),count);
            if (res < 0) ++count;
            return res;
        }
        else return mystoi(t.value());
    }
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subexpressions de l'expressió representada per t
//       amb avaluació estrictament menor que 0.
int numNegative(BinTree<string> t){
        int count = 0;
        aux(t,count);
        return count;
    }
   
