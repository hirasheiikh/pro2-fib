#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t){
    if(t.value() == "true") return BinTree<bool>(true);
    else if(t.value() == "false") return BinTree<bool>(false);
    else if(t.value() == "and"){
        BinTree<bool> izq = treeOfEvaluations(t.left());
        BinTree<bool> der = treeOfEvaluations(t.right());
        return BinTree<bool>(izq.value() and der.value(),izq,der);
    }
    else if(t.value() == "or"){
        BinTree<bool> izq = treeOfEvaluations(t.left());
        BinTree<bool> der = treeOfEvaluations(t.right());
        return BinTree<bool>(izq.value() or der.value(),izq,der);
    }
    else {
        BinTree<bool> izq = treeOfEvaluations(t.left());
        return BinTree<bool>(not izq.value(),izq,BinTree<bool>());
    }
}