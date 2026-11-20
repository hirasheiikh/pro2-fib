#include "evaluate.hh"
#include "utils.hh"

int evaluate(BinTree<string> t){
    if (t.left().empty() and t.right().empty()) return mystoi(t.value());
    else{
        int re = evaluate(t.left());
        int rd = evaluate(t.right());
        if (t.value() == "+") return re + rd;
        else if (t.value() == "-") return re - rd;
        else return re*rd; 
    }
}