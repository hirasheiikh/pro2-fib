#include "evaluate.hh"


bool evaluate(const BinTree<string> t){
    if (t.value() == "true") return true;
    else if (t.value() == "false") return false;
    else if (t.value() == "or"){
        if (evaluate(t.left()) == true) return true;
        else if (evaluate(t.right()) == true) return true;
        else return false;
    }
    else if (t.value() == "and"){
        if (evaluate(t.left()) == false) return false;
        else if (evaluate(t.right()) == false) return false;
        else return true;
    }
    else{
        if (evaluate(t.left()) == true) return false;
        else return true;
    }
    return 0;
}